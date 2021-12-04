#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll p = 3, q = 7, e = 2;
ll n = p * q;
ll phi = (p - 1) * (q - 1);

ll encrypt(int data) {
    while (e < n) {
        if (__gcd(phi, e) == 1) break;
        e++;
    }
    ll val = pow(data, e); val %= n;
    cout << val << endl;
    return val;
}

ll decrypt(int data) {
    ll d = (2 * phi + 1) / e;
    ll org_data = pow(data, d); org_data %= n;
    return org_data;
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
    cout << "ENTER DATA TO ENCRPYT " << endl; ll data; cin >> data;
    ll encrpyted_data = encrypt(data);
    cout << "ENCRYPTED DATA IS " << encrpyted_data << endl;
    ll decrptyed_data = decrypt(encrpyted_data);
    cout << "DENCRYPTED DATA IS " << decrptyed_data << endl;
    return 0;
}
