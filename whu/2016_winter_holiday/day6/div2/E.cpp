#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

char* s;
int tot,lenhalf,len,nn0,nn1,nn2,nn3,nn4,nn5,nn6,nn7,nn8,nn9;
int nn[10];
int lenl[10];
int totl[10];
vector<int> numOri(10);
// vector<int> nn;
int main(int argc, char const *argv[])
{
	while(scanf("%s",s)!=EOF)
	{
		numOri.clear();
		tot = 0;
		len = strlen(s);
		for (int i = 0; i < len; ++i)
		{
			numOri[s[i]-'0']++;
			tot += s[i]-'0';
		}
		lenhalf = (len+1)>>1;
		lenhalf1 = (len>>1);
		for (int nn1 = 0; nn1 <= numOri[1]; ++nn1)
		{
			nn[1] = nn1;
			lenl[1] = nn1;
			totl[1] = nn1;
			if (lenl[1]>lenhalf) break;
			for (int nn2 = 0; nn2 <= numOri[2]; ++nn2)
			{
				nn[2] = nn2;
				lenl[2] = lenl[1]+nn2;
				totl[2] = tot[1] + nn2*2;
				if (lenl[2]>lenhalf) break;
				for (int nn3 = 0; nn3 <= numOri[3]; ++nn3)
				{
					nn[3] = nn3;
					lenl[3] = lenl[2]+nn3;
					totl[3] = tot[2] + nn3*3;
					if (lenl[3]>lenhalf) break;
					for (int nn4 = 0; nn4 <= numOri[4]; ++nn4)
					{
						nn[4] = nn4;
						lenl[4] = lenl[3]+nn4;
						totl[4] = tot[3] + nn4*4;
						if (lenl[4]>lenhalf) break;
						for (int nn5 = 0; nn5 <= numOri[5]; ++nn5)
						{
							nn[5] = nn5;
							lenl[5] = lenl[4]+nn5;
							totl[5] = tot[4] + nn5*5;
							if (lenl[5]>lenhalf) break;
							for (int nn6 = 0; nn6 <= numOri[6]; ++nn6)
							{
								nn[6] = nn6;
								lenl[6] = lenl[5]+nn6;
								totl[6] = tot[5] + nn6*6;
								if (lenl[6]>lenhalf) break;
								for (int nn7 = 0; nn7 <= numOri[7]; ++nn7)
								{
									nn[7] = nn7;
									lenl[7] = lenl[6]+nn7;
									totl[7] = tot[6] + nn7*7;
									if (lenl[7]>lenhalf) break;
									for (int nn8 = 0; nn8 <= numOri[8]; ++nn8)
									{
										nn[8] = nn8;
										lenl[8] = lenl[7]+nn8;
										totl[8] = tot[7] + nn8*8;
										if (lenl[8]>lenhalf) break;
										for (int nn9 = 0; nn9 <= numOri[9]; ++nn9)
										{
											nn[9] = nn9;
											lenl[9] = lenl[8]+nn9;
											totl[9] = tot[8] + nn9*9;
											if (lenl[9]>lenhalf) break;
											if (lenl[9]+numOri[0]<lenhalf1) break;
											if (lenhalf!=lenhalf1)
											{
												nn[0] = lenhalf - lenl[9];
												if (nn[0]>=0&&nn[0]<=numOri[0])
												{
													if (((tot-totl[9])%11)!=(totl[9]%11)) break;
													k = lenhalf;
												}

												nn[0] = lenhalf1 - lenl[9];

											}
											else
											{

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
	return 0;
}