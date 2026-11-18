#include <iostream>
#include <netdb.h>
#include <arpa/inet.h>
using namespace std;

int main()
{
    char h[100];
    struct hostent *p;
    struct in_addr **a;

    cout << "Enter the domain name: ";
    cin >> h;

    p = gethostbyname(h);

    if (p == NULL)
    {
        cout << "DNS lookup failed." << endl;
        return 1;
    }

    cout << "\nHost Name: " << p->h_name << endl;
    cout << "IP Address: ";

    a = (struct in_addr **)p->h_addr_list;

    if (a[0] != NULL)
    {
        cout << inet_ntoa(*a[0]) << endl;
    }

    return 0;
}
