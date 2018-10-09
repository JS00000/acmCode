#include <map>
#include <string>
#include <iostream>
#include <algorithm>

#define maxn 234

using namespace std;

map<string, int> mp;
string s1, s2, st, en;
int n, c;
int degree_in[maxn], degree_out[maxn];

int main()
{
    cin >> n;
    c = 0;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        if (!mp.count(s1)) 
            mp[s1] = c++;
        if (!mp.count(s2)) 
            mp[s2] = c++;
        degree_out[mp[s1]]++;
        degree_in[mp[s2]]++;
    }
    for (map<string, int>::iterator i = mp.begin(); i != mp.end(); ++i)
    {
        if (degree_in[i->second] < degree_out[i->second])
            st = i->first;
        if (degree_in[i->second] > degree_out[i->second])
            en = i->first;
    }
    cout << st << " ";
    cout << en << endl;
    return 0;
}
