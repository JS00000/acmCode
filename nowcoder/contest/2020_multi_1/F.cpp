#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string a, b;
    while (cin >> a >> b) {
        int la = a.length();
        int lb = b.length();
        int i = 0;
        while (i < max(la, lb) * 10) {
            if (a[i % la] < b[i % lb]) {
                cout << "<" << endl;
                break;
            } else if (a[i % la] > b[i % lb]) {
                cout << ">" << endl;
                break;
            }
            i++;
        }
        if (i == max(la, lb) * 10) {
            cout << "=" << endl;
        }
    }

    return 0;
}
