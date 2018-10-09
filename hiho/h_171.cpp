#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define maxn 10007
using namespace std;

int n, k, out_idx = 0;
int group[maxn];
string email;
string names[maxn];
vector<int> output[maxn];
unordered_map<string, int> emails_map;

struct disjoint_set
{
    vector<int> fa, rank;
    disjoint_set(int n): fa(n), rank(n)
    {
        for (int i = 0; i < n; i++) fa[i] = i;
    }
    int find(int x)
    {
        return fa[x] = fa[x] == x ? x : find(fa[x]);
    }
    void merge(int x, int y)
    {
        int a = find(x), b = find(y);
        if (rank[a] < rank[b]) {
            fa[a] = b;
        } else {
            fa[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    disjoint_set s(n);
    for (int i = 0; i < n; i++) {
        group[i] = -1;
        cin >> names[i] >> k;
        for (int j = 0; j < k; j++) {
            cin >> email;
            if (emails_map.count(email)) {
                s.merge(emails_map[email], i);
            } else {
                emails_map[email] = i;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (group[s.find(i)] == -1) {
            group[s.find(i)] = out_idx;
            output[out_idx++].push_back(i);
        } else {
            output[group[s.find(i)]].push_back(i);
        }
    }
    for (int i = 0; i < out_idx; i++) {
        int k = output[i].size() - 1;
        for (int j = 0; j < k; j++) 
            cout << names[output[i][j]] << " ";
        cout << names[output[i][k]] << "\n";
    }
    return 0;
}
