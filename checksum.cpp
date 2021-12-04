#include <bits/stdc++.h>
using namespace std;

int get_num(string ss) {
    reverse(ss.begin(), ss.end());
    int num = 0;
    for (int i = 0; i < ss.size(); i++) num += (ss[i] == '1' ? (1 << i) : 0);
    return num;
}

string get_bin(int num) {
    string s = "";
    for (int i = 0; i < 7; i++) {
        if ((num >> i) & 1) s.push_back('1');
        else s.push_back('0');
    }
    reverse(s.begin(), s.end());
    return s;
}

int get_sum(string data) {
    vector<string> store;
    for (int i = 0; i < data.size(); i += 4) store.push_back(data.substr(i, 4));
    vector<int> nums;
    for (auto it : store) nums.push_back(get_num(it));
    int sum = 0; for (auto it : nums) sum += it;
    while (sum > 15) {
        string bin = get_bin(sum); reverse(bin.begin(), bin.end());
        string first = bin.substr(0, 4), sec = bin.substr(4, bin.size() - 4);
        reverse(first.begin(), first.end());  reverse(sec.begin(), sec.end());
        sum = get_num(first) + get_num(sec);
    }
    return sum;
}

string send(string data) {
    int sum = get_sum(data);
    string checksum = get_bin(sum); reverse(checksum.begin(), checksum.end());
    checksum = checksum.substr(0, 4);  reverse(checksum.begin(), checksum.end());
    for (int i = 0; i < 4; i++) checksum[i] = (checksum[i] == '1' ? '0' : '1');
    return checksum;
}

int check(string data, string checksum) {
    data = checksum + data;
    int sum = get_sum(data);
    string val = get_bin(sum);
    reverse(val.begin(), val.end());
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        if (val[i] == '0') cnt++;
    }
    if (cnt) return 0;
    else return 1;
}

int main() {
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
    // for printing erros
    freopen("Errors.txt", "w", stderr);
# endif
    string data;
    cout << "ENTER 16 BIT DATA WORD" << endl;
    cin >> data;
    string checksum = send(data);
    cout << "CHECKSUM IS " << checksum << endl;
    cout << "ENTER RECEIVER CODE" << endl;
    string rec_data; cin >> rec_data;
    int stat = check(rec_data, checksum);
    if (stat) cout << "NO ERROR" << endl;
    else cout << "ERROR" << endl;
    return 0;
}
