#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

const int dqx[8] = {0,0,-1,1,-1,1,-1,1};
const int dqy[8] = {1,-1,0,0,-1,1,1,-1};
const int dkx[8] = {-2,-1,1,2,2,1,-1,-2};
const int dky[8] = {1,2,2,1,-1,-2,-2,-1};
int n,m,ans,nq,nk,np;
int qx[110],qy[110],kx[110],ky[110],px[110],py[110];
bool mp[1010][1010];
bool flag[1010][1010];

using namespace std;
int main(int argc, char const *argv[])
{
	cin >> n >> m;
	int k = 0;
	while(n||m)
	{
		memset(mp,true,sizeof(mp));
		memset(flag,true,sizeof(flag));
		cin >> nq;
		for (int i = 0; i < nq; ++i)
		{
			cin >> qx[i] >> qy[i];
			mp[qx[i]][qy[i]] = false;
			flag[qx[i]][qy[i]] = false;
		}
		cin >> nk;
		for (int i = 0; i < nk; ++i)
		{
			cin >> kx[i] >> ky[i];
			mp[kx[i]][ky[i]] = false;
			flag[kx[i]][ky[i]] = false;
		}
		cin >> np;
		for (int i = 0; i < np; ++i)
		{
			cin >> px[i] >> py[i];
			mp[px[i]][py[i]] = false;
			flag[px[i]][py[i]] = false;
		}

		for (int i = 0; i < nq; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				int tx = qx[i]+dqx[j];
				int ty = qy[i]+dqy[j];
				while(flag[tx][ty]&&tx>0&&ty>0&&tx<=n&&ty<=m)
				{
					if (mp[tx][ty])
						mp[tx][ty] = false;
					tx+=dqx[j];
					ty+=dqy[j];
				}
			}
		}
		for (int i = 0; i < nk; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				int tx = kx[i]+dkx[j];
				int ty = ky[i]+dky[j];
				if (mp[tx][ty])
				{
					mp[tx][ty] = false;
					ans--;
				}
			}
		}
		ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				// cout << mp[i][j];
				if (mp[i][j]) ans++;
			}
			// cout << endl;
		}
		k++;
		cout << "Board " << k << " has " << ans << " safe squares.\n";
		cin >> n >> m;
	}
	return 0;
}