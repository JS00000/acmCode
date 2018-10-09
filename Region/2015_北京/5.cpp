#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


#define maxn 224737

template <typename T>
class Hash
{
private:
    int hashsize, count;
    vector<T> elem;
    vector<bool> flag;
    unsigned int BKDRHash(string str)
    {
        unsigned int seed = 1313; // 31 131 1313 13131 131313 etc..
        unsigned int hash = 0;
        for (std::string::iterator it = str.begin(); it != str.end(); ++it)
            hash = hash * seed + *it;
        return (hash & 0x7FFFFFFF);
    }
    unsigned int getHash(string x)
    {
        return BKDRHash(x) % hashsize;
    }
    unsigned int getHash(int x)
    {
        return ((x & 0x7FFFFFFF) % hashsize);
    }
    unsigned int getHash(pair<string, string> x)
    {
        return BKDRHash(x.first + ", " + x.second) % hashsize;
    }
    void collision_1(int &pos)
    {
        pos = (pos + 1) % hashsize;
    }
    int findHash(T x, int &pos)
    {
        int c = 0;
        pos = getHash(x);
        while(flag[pos] && elem[pos] != x)
        {
            // Avoid infinite loop.
            collision_1(pos);
            c++;
            if (c >= hashsize) return -2;
        }
        if (!flag[pos]) return 0;
        else return 1;
    }

public:
    Hash()
    {
        hashsize = maxn;
        elem.resize(hashsize);
        flag.resize(hashsize);
        count = 0;
    }

    int findHash(T x)
    {
        int pos = getHash(x), c = 0;
        while(flag[pos] && elem[pos] != x)
        {
            // Avoid infinite loop.
            collision_1(pos);
            c++;
            if (c >= hashsize) return -2;
        }
        //Not exist
        if (!flag[pos]) return -1;
        return pos;
    }

    int insert(T x)
    {
        int pos;
        if (findHash(x, pos) == 1) return pos;
        elem[pos] = x;
        flag[pos] = 1;
        count++;
        return pos;
    }

    void clear()
    {
        elem.clear();
        flag.clear();
        elem.resize(hashsize);
        flag.resize(hashsize);
        count = 0;
    }

    int size()
    {
        return count;
    }
};


int p[maxn];
int head[maxn];
int dist[maxn];
bool visit[maxn];

int qhead[maxn];
int qmap[maxn];
string id_to_name[maxn];
vector<int> name_to_id[maxn];

Hash<string> surnames;
Hash<string> qhead_hash;
Hash<pair<string, string> > qmap_hash;





// set<string> surnames;
// map<string, int> qhead;
// map<string, vector<int> > name_to_id;
// map<pair<string, string>, int> qmap;


struct node
{
    int to, next;
}edge[maxn];
struct snode
{
    int next;
    string to;
}qedge[maxn];
struct qnode
{
    string a, b;
}qq[maxn];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void LCA(int u, int d)
{
    p[u] = u;
    dist[u] = d;
    int k;
    visit[u] = true;
    for (k = head[u]; k != 0; k = edge[k].next)
    {
        if (!visit[edge[k].to])
        {
            LCA(edge[k].to, d + 1);
            p[edge[k].to] = u;
        }
    }
    for (k = qhead[qhead_hash.findHash(id_to_name[u])]; k != 0; k = qedge[k].next)
    {
        std::vector<int>::iterator j, j_first, j_last;
        j_first = name_to_id[surnames.findHash(qedge[k].to)].begin();
        j_last = name_to_id[surnames.findHash(qedge[k].to)].end();
        for (j = j_first; j != j_last; ++j)
        {
            if (visit[*j])
            {
                int lca = find(*j);
                int query1 = qmap_hash.findHash(make_pair(id_to_name[u], qedge[k].to));
                int query2 = qmap_hash.findHash(make_pair(qedge[k].to, id_to_name[u]));
                qmap[query1] = max(qmap[query1], dist[u] + dist[*j] - 2 * dist[lca]);
                qmap[query2] = max(qmap[query2], dist[u] + dist[*j] - 2 * dist[lca]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, q, a, b;
    char str[10], str2[10];
    while(~scanf("%d%d", &n, &q))
    {
        memset(head, 0, (n+1)*sizeof(int));
        memset(dist, 0, (n+1)*sizeof(int));
        memset(visit, 0, (n+1)*sizeof(bool));
        memset(qhead, 0, sizeof(qhead));
        memset(qmap, 0, sizeof(qmap));
        surnames.clear();
        qhead_hash.clear();
        qmap_hash.clear();
        for (int i = 0; i < maxn; ++i) id_to_name[i].clear();
        for (int i = 0; i < maxn; ++i) name_to_id[i].clear();

        for (int i = 0; i < n; ++i)
        {
            scanf("%s", str);
            id_to_name[i+1] = str;
            name_to_id[surnames.insert(str)].push_back(i+1);
        }
        for (int i = 1; i <= n-1; ++i)
        {
            scanf("%d%d", &a, &b);
            edge[i*2-1].to = b;
            edge[i*2-1].next = head[a];
            head[a] = i*2-1;
            edge[i*2].to = a;
            edge[i*2].next = head[b];
            head[b] = i*2;
        }
        for (int i = 1; i <= q; ++i)
        {
            scanf("%s%s", str, str2);
            if ((surnames.findHash(str) == -1) || (surnames.findHash(str2) == -1))
            {
                qq[i].a = qq[i].b = "";
                continue;
            }
            qq[i].a = str;
            qq[i].b = str2;
            if (qhead_hash.findHash(str) == -1) qhead[qhead_hash.insert(str)] = 0;
            if (qhead_hash.findHash(str2) == -1) qhead[qhead_hash.insert(str2)] = 0;

            qedge[i*2-1].to = str2;
            qedge[i*2-1].next = qhead[qhead_hash.findHash(str)];
            qhead[qhead_hash.findHash(str)] = i*2-1;
            qedge[i*2].to = str;
            qedge[i*2].next = qhead[qhead_hash.findHash(str2)];
            qhead[qhead_hash.findHash(str2)] = i*2;
            qmap[qmap_hash.insert(make_pair(str, str2))] = -1;
            qmap[qmap_hash.insert(make_pair(str2, str))] = -1;
        }
        LCA(1, 0);
        for (int i = 1; i <= q; ++i)
        {
            if (qq[i].a == "" || qq[i].b == "")
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", qmap[qmap_hash.findHash(make_pair(qq[i].a, qq[i].b))] + 1);
            }
        }
    }
    return 0;
}