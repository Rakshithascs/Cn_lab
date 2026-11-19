#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Nodes: ";
    cin >> n;
    int d[10][10];
    cout << "Enter matrix (999=no link):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> d[i][j];

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    cout << "Routing Table:\n";
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < n; j++) cout << d[i][j] << " ";
        cout << endl;
    }
    return 0;
}
