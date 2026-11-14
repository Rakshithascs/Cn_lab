#include <bits/stdc++.h>
using namespace std;
string calc(string c) {
    string p = "10001000000100001";
    for (int i = 0; i < (int)c.size() - 16; i++)
        if (c[i] == '1')
            for (int j = 0; j <= 16; j++)
                c[i + j] = (c[i + j] == p[j] ? '0' : '1');
    return c.substr(c.size() - 16);
}
int main() {
    string d, r;
    cout << "Enter the data to be sent: ";
    cin >> d;
    string crc = calc(d + string(16, '0'));
    cout << "CRC: " << crc << endl;
    cout << "Transmitted frame: " << d + crc << endl;
    cout << "Enter the received frame: ";
    cin >> r;
    string rc = calc(r);
    cout << "Receiver CRC: " << rc << endl;
    cout << (rc.find('1') == string::npos ? "Received frame is error-free." : "Error detected in received frame.");
    return 0;
}
