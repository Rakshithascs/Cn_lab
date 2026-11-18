#include <iostream>
using namespace std;

int main() {
    int n, w, i, ack;
    cout << "Enter total frames: ";
    cin >> n;
    cout << "Enter window size: ";
    cin >> w;

    for (i = 1; i <= n; i++) {
        cout << "Frame " << i << " Sent" << endl;
        if (i % w == 0 || i == n) {
            cout << "Waiting for ACK..." << endl;
            cout << "Enter ACK for frame " << i << ": ";
            cin >> ack;
            if (ack == i)
                cout << "ACK " << ack << " Received, Window Slides\n" << endl;
            else {
                cout << "ACK " << ack << " Lost, Resending from " << ack + 1 << "\n" << endl;
                i = ack;
            }
        }
    }
    cout << "All Frames Sent Successfully" << endl;
    return 0;
}
