#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w, i, ack;

    cout << "enter the total frame: ";
    cin >> n;
    cout << "window size: ";
    cin >> w;

    for (i = 1; i <= n; i++) {
        cout << "frames " << i << " sent" << endl;

        if (i % w == 0 || i == n) {
            cout << "waiting for ack...." << endl;
            cout << "enter ack for frame: " << i << " : ";
            cin >> ack;

            if (ack == i) {
                cout << "ack " << ack << " recieved, window sliding" << endl;
            } else {
                cout << "ack " << ack << " lost, resend from " << ack + 1 << endl;
                i = ack;
            }
        }
    }

    cout << "successfully sent" << endl;
    return 0;
}
