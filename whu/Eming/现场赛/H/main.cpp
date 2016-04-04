#include <cstdio>
#include <algorithm>

#define LENGTH 260000

using namespace std;

int main(int argc, char *argv[])
{
    long N, k, t, ans, max, j;
    long a[LENGTH],value[LENGTH];
    scanf("%ld", &N);
    while(N!=-1)
    {
                max = 0;
                for (int i = 0; i < LENGTH; i++)
                {   
                    a[i] = 0; 
                    value[i] = -1;    
                }
                for (int i = 0; i < N; i++)
                {
                    scanf("%ld",&k);
                    j = 0;
                    while(value[j]!=k&&value[j]!=-1) j++;
                    value[j] = k;
                    a[j]++;
                    if (a[j]>max)
                    {
                       max = a[j];
                       ans = value[j];
                       t = a[0];
                       a[0] = a[j];
                       a[j] = t;
                       t = value[0];
                       value[0] = value[j];
                       value[j] = t;
                    }
                    if ((max+(N-i))<N/2) break;
                }
                if  (max > N/2) 
                {
                    printf("%ld\n",ans);
                }
                else 
                {
                     printf("-1\n");
                }
                scanf("%ld", &N);
    }
    return 0;
}
