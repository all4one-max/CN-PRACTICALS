#include <bits/stdc++.h>
using namespace std;

string divisor = "1101";

string get_rem(string data) {
    int n = data.size(), m = divisor.size();
    for (int i = 0; i < n; i++) {
        if (i + m > n) continue;
        if (data[i] == '1') {
            for (int j = 0; j < m; j++) data[i + j] = (data[i + j] == divisor[j] ? '0' : '1');
        }
    }
    reverse(data.begin(), data.end()); string rem = data.substr(0, m - 1);
    reverse(rem.begin(), rem.end());
    return rem;
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
    cout << "ENTER THE DATA" << endl; cin >> data;
    cout << "THE DIVISOR OF THIS ALGORITHM IS " << divisor << endl;
    for (int i = 0; i < divisor.size() - 1; i++) data.push_back('0');
    string crc = get_rem(data);
    cout << "CRC IS " << crc << endl;
    cout << "ENTER RECEIVER DATA" << endl; string rec_data;
    cin >> rec_data;
    string rem = get_rem(rec_data);
    int ok = 1;
    for (auto it : rem) ok = (it == '1' ? 0 : ok);
    if (ok) cout << "NO ERROR" << endl;
    else cout << "ERROR" << endl;
    return 0;
}
