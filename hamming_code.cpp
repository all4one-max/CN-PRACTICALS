#include <bits/stdc++.h>
using namespace std;

int reduntant_bits;

string get_ham_code(string data) {
    int n = data.size(), j = n - 1;
    string ham_code(n + reduntant_bits, '0'); int m = n + reduntant_bits;
    for (int i = m - 1; i >= 0 ; i--) if (__builtin_popcount(m - i) != 1) ham_code[i] = data[j--];
    vector<int> cnt(33, 0);
    for (int i = 0; i < m; i++) {
        int ind = m - i;
        if (ham_code[i] == '1') {
            for (int j = 0; j < 32; j++) {
                if ((ind >> j) & 1) cnt[j]++;
            }
        }
    }
    int start = reduntant_bits - 1;
    for (int i = m - 1; i >= 0 ; i--) {
        if (__builtin_popcount(m - i) == 1) {
            if (cnt[start] % 2) ham_code[i] = '1';
            start--;
        }
    }
    return ham_code;
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
    int n = data.size();
    reduntant_bits = 1;
    while (true) {
        if ((1 << reduntant_bits) >= (n + reduntant_bits + 1)) break;
        reduntant_bits++;
    }
    string ham_code = get_ham_code(data);
    cout << "HAM CODE IS " << ham_code << endl;
    return 0;
}
