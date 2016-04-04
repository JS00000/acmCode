#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

typedef long long ll;

using namespace std;


int T,n,m;
vector<int> g[20];
int du[20],L[20],w[20];

bool toposortInc()
{
	bool p[20];	
	memset(p, true, sizeof(p));
	memset(du, 0, sizeof(du));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < g[i].size(); ++j)
		{
			du[g[i][j]]++;
		}
	}
	int tot = 0, k;
	int min = 100000;
	queue<int> Q;
	for (int i = 0; i < n; ++i)
		if (!du[i]&&w[i]<min)
		{
			min = w[i];
			k = i;
		} 
	Q.push(k);
	p[k] = false;
	while(!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		L[tot++] = x;
		for (int j = 0; j < g[x].size(); ++j)
		{
			int t = g[x][j];
			du[t]--;
		}
		min = 100000;
		for (int i = 0; i < n; ++i)
		{
			if (!du[i]&&w[i]<min&&p[i])
			{
				min = w[i];
				k = i;
			}
		}
		if (min!=100000)
		{
			Q.push(k);
			p[k] = false;
		}
	}
	if (tot == n) return 1;
	else return 0;
}




vector<string> split(string str,string pattern)
{
    string::size_type pos;
    vector<string> result;
    str+=pattern;
    int size=str.size();


    for(int i=0; i<size; i++)
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



int main(int argc, char const *argv[])
{
	cin >> T;
	while(T)
	{
		bool flag;
		string str;
		string name[20];
		vector<string> sp;
		cin >> n >> m;
		getchar();
		for (int i = 0; i < n; ++i)
		{
			getline(cin, str);
			sp = split(str," ");
			int l=sp.size()-1;
			for (int j = 0; j < l; ++j)
			{
				name[i] += sp[j];
				if (j!=sp.size()-2)
				{
					name[i] += " ";
				}
			}
			int temp = 0;
			for (int j = 0; j < sp[l].length(); ++j)
			{
				temp = temp*10+(sp[l][j]-'0');
			}
			w[i] = temp;
		}

		for (int i = 0; i < 20; ++i)
		{
			g[i].clear();
		}

		for (int i = 0; i < m; ++i)
		{
			int t1,t2;
			getline(cin, str);
			sp = split(str," --> ");
			for (int j = 0; j < n; ++j)
			{
				if (sp[0]==name[j]) t1 = j;
				if (sp[1]==name[j]) t2 = j;
			}
			flag = true;
			for (int j = 0; j < g[t1].size(); ++j)
				if (g[t1][j]==t2) flag=false;
			if (flag)
				g[t1].push_back(t2);
		}

		if (toposortInc())
		{
			// cout << "OK\n";
			long long ans=0;
			for (int i = 0; i < n; ++i)
			{
				// cout << name[L[i]] << " --> ";
				ans+=w[L[i]]*(i+1);
			}
			cout << ans <<endl;
		}
		else
		{
			// cout << "NO\n";
		}


		T--;
	}
	return 0;
}