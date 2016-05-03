#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>

#define LL long long
#define MAXN 0x0fffffff

using namespace std; 

struct pos
{
	int x;
	int y;
};
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};


bool mp[3][4] = {0};
pos dir[12] = {0};


bool check(int j[])
{
	int select = 0;
	memset(mp,0,sizeof(mp));
	for (int i = 0; i < 12; ++i)
	{
		if (j[i])
		{
			dir[select].y = i/4;
			dir[select].x = i%4;
			select++;
			mp[i/4][i%4] = 1;
		}
	}
	if (select!=5) return 0;
	pos queue[100];
	int iq = 1;
	bool flag = 0;
	int i = 1;
	queue[iq++] = dir[0];
	mp[dir[0].y][dir[0].x] = 0;
	while(i<iq)
	{
		for (int k = 0; k < 4; ++k)
		{
			if ((queue[i].x+dx[k])>=4||(queue[i].x+dx[k])<0) 
			{
				continue;
			}
			if ((queue[i].y+dy[k])>=3||(queue[i].y+dy[k])<0) 
			{				
				continue;
			}
			if (mp[queue[i].y+dy[k]][queue[i].x+dx[k]]==1)
			{
				mp[queue[i].y+dy[k]][queue[i].x+dx[k]] = 0;
				queue[iq].y = (queue[i].y+dy[k]);
				queue[iq].x = (queue[i].x+dx[k]);
				iq++;
			}
		}
		i++;
	}
	if (i==6)
	{
		flag = 1;
	}
	if (flag)
	{
		for (int i = 0; i < 12; ++i)
		{
			if (j[i])
			{
				cout << i << " " ;
			}
		}
		cout << endl;
		for (int k = 1; k < iq; ++k)
		{
			// cout << queue[k].y*4+queue[k].x  << " ";
			cout << queue[k].y << " " <<  queue[k].x << " , " ;
		}
		cout << endl;
	}
	return flag;
}

int main(int argc, char const *argv[])
{
	/* code */
	LL sum = 0,t = 0,p,q;
	int j[20] = {0};
	for (j[0] = 0; j[0] <=1; ++j[0])
	{
		for (j[1] = 0; j[1] <=1; ++j[1])
		{
			// if (j[0]==j[1]) continue;
			for (j[2] = 0; j[2] <=1; ++j[2])
			{
				// if (j[0]==j[2]||j[1]==j[2]) continue;
				for (j[3] = 0; j[3] <=1; ++j[3])
				{
					// if (j[0]==j[3]||j[1]==j[3]||j[2]==j[3]) continue;
					for (j[4] = 0; j[4] <=1; ++j[4])
					{
						// if (j[0]==j[4]||j[1]==j[4]||j[2]==j[4]||j[3]==j[4]) continue;
						for (j[5] = 0; j[5] <=1; ++j[5])
						{
							// if (j[0]==j[5]||j[1]==j[5]||j[2]==j[5]||j[3]==j[5]||j[4]==j[5]) continue;
							for (j[6] = 0; j[6] <=1; ++j[6])
							{
								// if (j[0]==j[6]||j[1]==j[6]||j[2]==j[6]||j[3]==j[6]||j[4]==j[6]||j[5]==j[6]) continue;
								for (j[7] = 0; j[7] <=1; ++j[7])
								{
									// if (j[0]==j[7]||j[1]==j[7]||j[2]==j[7]||j[3]==j[7]||j[4]==j[7]||j[5]==j[7]||j[6]==j[7]) continue;
									for (j[8] = 0; j[8] <=1; ++j[8])
									{
										// if (j[0]==j[8]||j[1]==j[8]||j[2]==j[8]||j[3]==j[8]||j[4]==j[8]||j[5]==j[8]||j[6]==j[8]||j[7]==j[8]) continue;
										for (j[9] = 0; j[9] <=1; ++j[9])
										{
											// if (j[0]==j[9]||j[1]==j[9]||j[2]==j[9]||j[3]==j[9]||j[4]==j[9]||j[5]==j[9]||j[6]==j[9]||j[7]==j[9]||j[8]==j[9]) continue;
											for (j[10] = 0; j[10] <=1; ++j[10])
											{
												for (j[11] = 0; j[11] <= 1; ++j[11])
												{
													// sum++;
													if (check(j))
													{
														sum++;
													}

												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << sum << endl;
	cin.get();
	return 0;
}
