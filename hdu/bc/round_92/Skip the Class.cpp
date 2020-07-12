#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#define maxn 1007
using namespace std;

class myc
{
    int d1, d2;
public:
    myc(){d1 = 0;d2 = 0;};
    ~myc(){};
    void add(int t)
    {
        if (t > d1)
        {
            d2 = d1;
            d1 = t;
        }
        else if (t > d2) d2 = t;
    }
    int sum()
    {
        return d1+d2;
    }
};

map<string, myc> mp;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, t;
        string cname;
        mp.clear();
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> cname >> t;
            mp[cname].add(t);
        }
        int ans = 0;
        for (std::map<string, myc>::iterator i = mp.begin(); i != mp.end(); ++i)
            ans += i->second.sum();
        cout << ans << endl;
    }
    return 0;
}
