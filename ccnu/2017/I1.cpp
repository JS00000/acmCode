#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
const int  maxn = 1e6 + 5;
multiset <long long > mst;
multiset <long long > :: iterator it1, it2;
long long  ans[maxn];
bool cmp(long long  a, long long  b)
{
    return a > b;
}
int main()
{
    //freopen("I.in","r",stdin);
    //freopen("I.out","w",stdout);
    int T;
    scanf("%d", &T);
    for(int cas=1;cas<=T;cas++)
    {
        mst.clear();
        int n, m, k, cnt = 0;
        long long  num;
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i < n; ++i)
        {
            scanf("%lld", &num);
            if(num <= k)
            {
                mst.insert(num);
            }
        }
        while(true)
        {
            int sz = mst.size();
            if(sz < 2)
                break;
            it1 = mst.end();
            it1--;
            long long  fst = *it1;
            mst.erase(it1);
            it2 = mst.lower_bound(min(fst, k - fst));
            if(it2 == mst.end())
                it2--;
            if(it2 == mst.begin() && *it2 > (k - fst))
                continue;
            if(*it2 <= k - fst)
            {
                ans[cnt++] = fst * ( *it2);
                mst.erase(it2);
            }
            else
            {
                it2 --;
                ans[cnt++] = fst * (*it2);
                mst.erase(it2);
            }
        }
        sort(ans, ans + cnt, cmp);
        long long  res = 0;
        for(int i = 0; i < min(m, cnt); ++i)
        {
            res += ans[i];
        }
        printf("CASE #%d: %lld\n",cas,res);
    }
    return 0;
}
