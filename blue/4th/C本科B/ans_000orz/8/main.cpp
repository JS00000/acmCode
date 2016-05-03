#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

bool a[1010] = {0} , b[1010] = {0};

int main()
{
    string st1,st2;
    cin >> st1 >> st2;
    int n = st1.length();
    for(int i=0;i<n;i++)
    {
        if (st1[i]=='*') a[i] = 1;
        else a[i] = 0;
        if (st2[i]=='*') b[i] = 1;
        else b[i] = 0;
    }
    int ans = 0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]==b[i]) continue;
        ans++;
        a[i+1] ^= 1;
    }
    if (a[n-1]!=b[n-1]) ans = -1;
    cout << ans << endl;
    return 0;
}
