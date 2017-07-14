#include<bits/stdc++.h>
using namespace std;
typedef long long LL; 

const int maxn = 1e5 + 10;
vector<int> c[26];
map<int,vector<int> > b;
int n,tot,sum[maxn],it[26];
char s[maxn];
LL ans;

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int z=1;z<=T;++z)
    {
        scanf("%s",s);
        n = strlen(s);
        sum[n] = 0;
        for(int i=n-1;i>=0;--i) sum[i] = sum[i+1]^(1<<(s[i]-'a'));
        for(int i=0;i<26;++i) c[i].clear();
        for(int i=0;i<n;++i) 
        {
            b[sum[i]].push_back(i);
            c[s[i]-'a'].push_back(i);
        }
        for(int i=0;i<26;++i) it[i] = int(c[i].size()) - 1;
        ans = 0;
        for(int i=n-1;i>=0;--i)
        {
            vector<int> p;
            for(int j=0;j<26;++j) if(it[j] >= 0) p.push_back(c[j][it[j]]);
            sort(p.begin(),p.end(),greater<int>());
            p.push_back(0);
            int mask = 0;
            for(int j=0;j<p.size()-1;++j)
            {
                mask |= 1<<(s[p[j]]-'a');
                //printf("%d %lld .. %d %d\n",b[mask^sum[i+1]].size(),ans,p[j],p[j+1]);
                vector<int>& t = b[mask^sum[i+1]];
                ans += int(upper_bound(t.begin(),t.end(),p[j]) 
                         - lower_bound(t.begin(),t.end(),p[j+1]));
            }
            it[s[i]-'a']--;
        }
        printf("CASE #%d: %lld\n",z,ans);
        b.clear();
    }
    return 0;
}
