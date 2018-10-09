#include <string>
#include <iostream>
#include <algorithm>
#define maxn 107
using namespace std;

struct node
{
    string st;
    int sn;
} a[maxn];

bool cmp(node a, node b)
{
    return a.st == b.st ? a.sn < b.sn : a.st < b.st;
}

int main()
{
    int n;
    string t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        int len = t.length();
        int k = 0;
        while (!(t[k] >= '0' && t[k] <= '9')) 
            k++;
        string st;
        st = t.substr(0, k);
        int sn = 0;
        for (int j = k; j < len; j++) 
            sn = sn * 10 + t[j] - '0';
        a[i].st = st;
        a[i].sn = sn;
    }
    sort(a, a+n, cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i].st << a[i].sn << endl;
    }
    return 0;
}
