#include <map>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#define maxn 100007
using namespace std;

int fa[maxn], level[maxn];
int find(int x)
{
    return fa[x] = fa[x] == x ? x : find(fa[x]);
}
void merge(int x, int y)
{
    int a = find(x), b = find(y);
    if (level[a] < level[b]) {
        fa[a] = b;
    } else {
        fa[b] = a;
        if (level[a] == level[b]) {
            level[a]++;
        }
    }
}

map<string, int> group;

int main()
{
    std::ios::sync_with_stdio(false);
    int n, idx = 0, p;
    cin >> n;
    for (int i = 0; i < 2*n; i++) {
        fa[i] = i;
        level[i] = 0;
    }
    string name1, name2;
    for (int i = 0; i < n; i++) {
        cin >> p >> name1 >> name2;
        if (p == 0) {
            if (!group.count(name1)) group[name1] = idx++;
            if (!group.count(name2)) group[name2] = idx++;
            merge(group[name1], group[name2]);
        } else {
            if (!group.count(name1) || !group.count(name2)) cout << "no" << endl;
            else cout << (find(group[name1]) == find(group[name2]) ? "yes": "no") << endl;
        }
    }

    return 0;
}
