#include <bits/stdc++.h>
using namespace std;

int frames, window_size;

int main() {
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
    // for printing erros
    freopen("Errors.txt", "w", stderr);
# endif
    srand(time(NULL));
    int num_of_transmission = 0;
    cout << "ENTER NUMBER OF FRAMES" << endl; cin >> frames;
    cout << "ENTER WINDOW SIZE" << endl; cin >> window_size;
    int i = 1;
    while (i <= frames) {
        for (int j = i; j < i + window_size && j <= frames; j++) {
            cout << "SENT FRAME " << j << endl;
            num_of_transmission++;
        }
        int x = 0;
        for (int j = i; j < i + window_size && j <= frames; j++) {
            int stat = (rand() % 50) % 2;
            if (!stat) break;
            else cout << "RECEIVED ACKNOWLEDGEMENT FOR FRAME " << j << endl;
            x++;
        }
        i += x;
    }
    cout << "TOTAL NUMBER OF TRANSMISSIONS ARE " << num_of_transmission << endl;
    return 0;
}
