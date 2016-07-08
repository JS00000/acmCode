#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 200020;
int s[maxn];
int main()
{
    int n;
    int ml = 1000000001;
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
        if(s[i] < ml) ml = s[i];
    }
    int ans_ = 0;
    for(int i = 0; i < n; i++) if(s[i] == ml) {
        int k = 0;
        for(int j = 1; j < n; j++)
            if(s[(i+n-j)%n] > s[i]) k++;
            else break;
        ans_ = (k > ans_)? k: ans_;
    }
    long long ans = (long long)n * (long long)ml + (long long)ans_;
    cout << ans << endl;
    return 0;
}
