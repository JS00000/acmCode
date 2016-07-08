#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
using namespace std;

char s[20], last[20];
int cnt[2];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        cnt[0] = cnt[1] = 0;
        int group = 0;
        strcpy(last, "END");
        while(true)
        {
            scanf("%s", s);
            if(strcmp(s, "END") == 0)
                break;
            if(strcmp(s, last) == 0)
                group = 1 - group;
            cnt[group]++;
            strcpy(last, s);
        }
        printf("%d\n", cnt[0]*cnt[1]);
    }
    return 0;
}
