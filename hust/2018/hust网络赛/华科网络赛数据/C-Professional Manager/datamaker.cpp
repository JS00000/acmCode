#include <bits/stdc++.h>
#include <unistd.h>
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

int main()
{
    for(int i = 1; i <= 15; i++){
        usleep(10000);
        string s = "./run " + to_string(i) + " > "+ to_string(i) + ".in";
        cout << s << endl;
        system(s.c_str());
        string t = "./DSU < " + to_string(i) + ".in > " + to_string(i) + ".out";
        cout << t << endl;
        system(t.c_str());
    }
    return 0;
}

