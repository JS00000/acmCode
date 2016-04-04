#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

typedef long long ll;

using namespace std;

long n,m,ans,len;
bool p;
string str,abb;
vector<string> ins,sp,phrase;

vector<string> split(string str,string pattern)
{
    string::size_type pos;
    vector<string> result;
    str+=pattern;
    unsigned long size=str.size();
    
    
    for(unsigned long i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            string s=str.substr(i,pos-i);
            result.push_back(s);
            i=pos+pattern.size()-1;
        }
    }
    return result;
}

void dfs(int d, int t, int j)
{
	if (t>m)
	{
		if ((t==m+1)&&(d==len))
		{
			ans++;
			// cout << d<<" "<<t<<" "<<j<<endl;
			return;
		}
		return;
	}
	if (len-m>d-t) return;
	if (d>len) return;
	for (int i = j; i < phrase[d-1].length(); ++i)
	{
		if (abb[t-1]==phrase[d-1][i])
		{
			dfs(d,t+1,i+1);
			dfs(d+1,t+1,0);
		}
	}
}

int main(int argc, char const *argv[])
{
	cin >> n;
	while(n)
	{
		ins.clear();
		for (int i = 0; i < n; ++i)
		{
			cin >> str;
			ins.push_back(str);
		}
		getchar();

		// cout << endl;
		// for (int i = 0; i < ins.size(); ++i)
		// {
		// 	cout << ins[i] << " ";
		// }
		// cout << endl;

		getline(cin,str);
		while(str!="LAST CASE")
		{
			phrase.clear();
			sp = split(str, " ");
			m = sp[0].length();
			for (int i = 0; i < m; ++i)
			{
				abb[i] = sp[0][i]-'A'+'a';
				// cout << abb[i];
			}
			// cout << endl;
			for (int i = 1; i < sp.size(); ++i)
			{
				p = true;
				for (int j = 0; j < ins.size(); ++j)
					if (sp[i]==ins[j]) p = false;
				if (p) phrase.push_back(sp[i]);
			}
			len = phrase.size();

			// for (int i = 0; i < len; ++i)
			// {
			// 	cout << phrase[i] << " ";
			// }
			// cout << endl;

			ans = 0;
			dfs(1,1,0);
			if (!ans)
			{
				cout << sp[0] << " is not a valid abbreviation\n";
			}
			else
			{
				cout << sp[0] << " can be formed in " << ans << " ways\n";
			}
			getline(cin, str);
		}
		cin >> n;
	}
	return 0;
}