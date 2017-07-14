#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#define maxn 100
using namespace std;


int main()
{
    string name[maxn];
    int i, n, w, s, next[maxn];
    char c;
    cin >> n;
    for (i = 1; i <= n; ++i) cin >> name[i];
    for (i = 1; i <= n; ++i) next[i] = i+1;
    cin >> w >> c >> s;
    next[n] = 1, w = w - 1;
    if (w == 0) w = n;
    while(n--)
    {
        int jmp = s;
        while(--jmp) w = next[w];
        cout << name[next[w]] << endl;
        next[w] = next[next[w]];
    }
    return 0;
}
