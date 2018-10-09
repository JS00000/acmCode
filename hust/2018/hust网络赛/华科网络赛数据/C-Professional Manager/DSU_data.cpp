#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5;
stringstream ss;

int main(int argc, char *argv[])
{
    int seed=time(NULL);
    if(argc > 1)
    {
        ss.clear();
        ss<<argv[1];
        ss>>seed;
    }
    srand(seed);
    int T = 10;
    printf("%d\n", T);
    while(T--){
        int n = rand()%maxn+1, q = rand()%maxn+1;
        printf("%d %d\n", n, q);
        for(int i = 0; i < q; i++){
            int t = rand()%4+1;
            printf("%d ", t);
            if(t == 1 || t == 4){
                int u = rand()%n+1, v = rand()%n+1;
                while(u == v){
                    u = rand()%n+1, v = rand()%n+1;
                }
                printf("%d %d\n", u, v);
            }
            else if(t == 2 || t == 3){
                int u = rand()%n+1;
                printf("%d\n", u);
            }
        }
    }
    return 0;
}

