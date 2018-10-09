#include<cstdio>
#include<cstring>
#include<fstream>
#include<iostream>

using namespace std;

const int maxn=1e4+10;

int n,m,a,b;
int z[maxn];

int main(int argc,char* argv[])
{    
	ifstream output("user_output");
	ifstream input("input");
	input>>n;
    for(int i=1;i<=n;i++)
        input>>z[i];

    output>>m;
    if(m>100000000||m==-1)return 1;
    for(int i=1;i<=m;i++)
    {
        output>>a>>b;
        if(z[a]>=z[b])z[a]-=z[b],z[b]*=2;
        else return 1;
		if(a>n||b>n||a<=0||b<=0)return 1;
    }

    int cnt=0;
    for(int i=1;i<=n;i++)
        if(z[i])cnt++;
    if(cnt==2)return 0;
    return 1;
}
