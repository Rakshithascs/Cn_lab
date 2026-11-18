#include <bits/stdc++.h>
using namespace std;

int main() {
    int d[4], h[8];

    cout << "Enter 4 bits: ";
    for (int i = 0; i < 4; i++) {
        cin >> d[i];
    }

    h[3] = d[0];
    h[5] = d[1];
    h[6] = d[2];
    h[7] = d[3];

    h[1] = (h[3] + h[5] + h[7]) % 2;
    h[2] = (h[3] + h[6] + h[7]) % 2;
    h[4] = (h[5] + h[6] + h[7]) % 2;

    cout << "Code: ";
    for (int i = 1; i <= 7; i++) {
        cout << h[i];
    }
    cout << endl;

    int p;
    cout << "Error pos: ";
    cin >> p;

    if (p != 0) {
        h[p] = !h[p];
    }

    int e = (h[1] + h[3] + h[5] + h[7]) % 2
          + ((h[2] + h[3] + h[6] + h[7]) % 2) * 2
          + ((h[4] + h[5] + h[6] + h[7]) % 2) * 4;

    if (e == 0) {
        cout << "No error" << endl;
    } else {
        cout << "Error at " << e << " corrected" << endl;
        h[e] = !h[e];
        cout << "Corrected code: ";
        for (int i = 1; i <= 7; i++) {
            cout << h[i];
        }
        cout << endl;
    }

    return 0;
}
