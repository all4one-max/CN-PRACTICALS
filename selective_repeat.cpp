#include <bits/stdc++.h>
using namespace std;

int frames, window_size;
int send(int seq) {
    int flag = rand() % 5;
    if (!flag) {
        cout << "FAILED TO SEND " << seq << endl;
        return 0;
    }
    else cout << "FRAME " << seq << " SUCCESSFULLY SENT" << endl;
    return 1;
}

int receive(int seq) {
    int flag = rand() % 5;
    if (!flag) {
        cout << "FAILED TO RECEIVE " << seq << endl;
        return 0;
    }
    else cout << "FRAME " << seq << " SUCCESSFULLY RECEIVD" << endl;
    return 1;
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
    srand(time(NULL));
    int num_of_transmission = 0;
    cout << "ENTER NUMBER OF FRAMES" << endl; cin >> frames;
    cout << "ENTER WINDOW SIZE" << endl; cin >> window_size;
    vector<int> rec(frames + 1, 0);
    int i = 1;
    while (i <= frames) {
        for (int j = i; j < i + window_size && j <= frames; j++) {
            cout << "SENDING FRAME " << j << endl;
            num_of_transmission++;
            int stat = send(j);
            if (stat) {
                int stat2 = receive(j);
                if (stat2) rec[j] = 1;
            }
        }
        int framesLeft = 1;
        while (framesLeft) {
            int cnt = 0;
            for (int j = i; j < i + window_size && j <= frames; j++) {
                if (!rec[j]) {
                    cout << "RESENDING FRAME " << j << endl;
                    num_of_transmission++;
                    int stat = send(j);
                    if (stat) {
                        int stat2 = receive(j);
                        if (stat2) rec[j] = 1;
                    }
                    cnt++;
                }
            }
            if (!cnt) framesLeft = false;
        }
        i += window_size;
    }
    cout << "TOTAL NUMBER OF TRANSMISSIONS ARE " << num_of_transmission << endl;
    return 0;
}
