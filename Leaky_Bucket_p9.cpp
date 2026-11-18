#include <bits/stdc++.h>
using namespace std;

int main() {
    int b, r, n;
    cout << "Bucket size: ";
    cin >> b;
    cout << "Output Rate: ";
    cin >> r;
    cout << "No of packets: ";
    cin >> n;

    int rem = 0;

    for (int i = 1; i <= n; i++) {
        int s;
        cout << "Packet " << i << " size: ";
        cin >> s;

        if (s + rem > b) {
            cout << "Packet " << i << " Dropped! Bucket Overflow" << endl;
        }
        else {
            rem = rem + s;
            cout << "Packet " << i << " Accepted, Bucket = " << rem << endl;
            rem = rem - r;
            if (rem < 0) {
                rem = 0;
            }
            cout << "Packet left / leak: " << rem << endl;
        }
    }
    return 0;
}
