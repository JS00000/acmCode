#include <map>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#define maxn 1007
using namespace std;

map<int, string> id;
map<int, int> sit;

int main()
{
    std::ios::sync_with_stdio(false);
    int n, sit1, sit2;
    string sid;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> sid >> sit1 >> sit2;
        id[sit1] = sid;
        sit[sit1] = sit2;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> sit1;
        cout << id[sit1] << " " << sit[sit1] << endl;
    }
    return 0;
}
