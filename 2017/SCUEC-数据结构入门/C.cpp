#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

class myCmp
{
    bool reverse;
public:
    myCmp(const bool& revparam=false) {reverse=revparam;}
    bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const
    {
        if (reverse) return (lhs.first==rhs.first?lhs.second>rhs.second:lhs.first>rhs.first);
        else return (lhs.first==rhs.first?lhs.second<rhs.second:lhs.first<rhs.first);
    }
};

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        priority_queue<pair<int, int>, vector<pair<int, int> >, myCmp> q(myCmp(true));
        pair<int, int> pt;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d", &pt.first, &pt.second);
            q.push(pt);
        }
        int j = 0, dist = 0;
        while(q.size())
        {
            j++;
            pt = q.top();
            dist = pt.first;
            q.pop();
            if (j & 1)
            {
                pt.first = pt.first + pt.second;
                q.push(pt);
            }
        }
        printf("%d\n", dist);
    }
    return 0;
}
