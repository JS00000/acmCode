#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int T[100][100];

int main()
{
    T[0][0] = 1;
    T[1][0] = 0;
    T[1][1] = 2;
    for (int n = 2; n < 7; n++)
        for (int k = 0; k <= n; k++)
            T[n][k] =   2*(2*n-k)*T[n-1][k-1] + 
                        ((2*n-1-k)*(2*n-2-k)+2*k)*T[n-1][k] + 
                        2*(k+1)*(2*n-2-k)*T[n-1][k+1] + 
                        (k+2)*(k+1)*T[n-1][k+2];
    for (int n = 0; n < 7; n++)
    {
        for (int k = 0; k <= n; k++)
            printf("%d ", T[n][k]);
        printf("\n");
    }
    return 0;
}
