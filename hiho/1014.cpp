// Trie树
#include <cstdio>
#include <vector>

using namespace std;

const int CHARSET = 27, BASE = 'a'-1;
vector<int> zeros;
struct Trie
{
    int tot, root;
    vector<vector<int> > child;
    Trie()
    {
        zeros.resize(27);
        child.push_back(zeros);
        child.push_back(zeros);
        root = tot = 1;
    }
    void insert(const char *str)
    {
        child[root][0]++;
        int chi = root;
        int now;
        for (const char *p = str; *p; ++p)
        {
            now = chi;
            chi = child[now][*p-BASE];
            if (chi == 0)
            {
                child[now][*p-BASE] = ++tot;
                chi = tot;
                child.push_back(zeros);
                child[tot][0] = 1;
            }
            else child[chi][0]++;
        }
    }
    int query(const char *str)
    {
        int cur = root;
        for (const char *p = str; *p && cur; ++p)
            cur = child[cur][*p - BASE];
        return child[cur][0];
    }
};


int main(int argc, char const *argv[])
{
    Trie tree;
    int n;
    char c[20];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", c);
        tree.insert(c);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", c);
        printf("%d\n", tree.query(c));
    }
    return 0;
}
