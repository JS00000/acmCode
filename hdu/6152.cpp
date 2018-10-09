// hdu 6152

// when n >= 6 printf Bad Team!

#include <math.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long long ull;

int n;
ull relation_1[3007][50];
ull relation_2[3007][50];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) 
    {
        scanf("%d", &n);
        int WIDTH = (n-1)/64+1;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < WIDTH; j++) 
            {
                relation_1[i][j] = 0;
                relation_2[i][j] = 0;
            }
            for (int j = i+1; j < n; j++) 
            {
                int tmp;
                scanf("%d", &tmp);
                if (tmp) relation_1[i][j/64] |= (1<<(j%64));
                else relation_2[i][j/64] |= (1<<(j%64));
            }
        }
        bool whatfuck = 1;
        for (int i = 0; i < n; i++) 
            for (int j = i+1; j < n; j++) 
                if (relation_1[i][j/64] & (1<<(j%64))) 
                    for (int k = 0; k < WIDTH; k++) 
                        if (relation_1[i][k] & relation_1[j][k]) whatfuck = 0;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (relation_2[i][j/64] & (1<<(j%64)))
                    for (int k = 0; k < WIDTH; k++)
                        if (relation_2[i][k] & relation_2[j][k]) whatfuck = 0;
        if (whatfuck) printf("Great Team!\n");
        else printf("Bad Team!\n");
    }
    return 0;
}
