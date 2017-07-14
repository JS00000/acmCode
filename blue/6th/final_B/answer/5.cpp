#include <cstdio>
#define maxn 100070

int n, L;
int d[maxn], t[maxn];
unsigned long long P[maxn], T[maxn];

unsigned long long F(int l, int r)
{
    return T[r] - T[l] - P[l]*(d[r] - d[l]);
}

int main()
{
    scanf("%d%d", &n, &L);
    P[0] = 0; T[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", d+i, t+i);
        P[i] = P[i-1] + t[i];
        T[i] = T[i-1] + P[i-1]*(d[i] - d[i-1]);
    }
    d[n+1] = L; t[n+1] = 0;
    P[n+1] = P[n]; T[n+1] = T[n] + P[n]*(d[n+1] - d[n]);
    if (n <= 4)
    {
        printf("0\n");
        return 0;
    }
    unsigned long long ans = (0llu-1), temp;
    for (int i = 2; i <= n-1; ++i)
    {
        int s1, s2 = i, s3, l = 1, r = i-1, m1, m2;
        while(l < r)
        {
            m1 = (l*2+r)/3;
            m2 = (l+r*2+1)/3;
            if (F(0, m1) + F(m1, i) < F(0, m2) + F(m2, i)) r = m2-1;
            else l = m1+1;
        }
        s1 = r;
        l = i+1, r = n;
        while(l < r)
        {
            m1 = (l*2+r)/3;
            m2 = (l+r*2+1)/3;
            if (F(i, m1) + F(m1, n+1) < F(i, m2) + F(m2, n+1)) r = m2-1;
            else l = m1+1;
        }
        s3 = r;
        temp = F(0, s1) + F(s1, s2) + F(s2, s3) + F(s3, n+1);
        if (temp < ans)  ans = temp;
    }
    printf("%llu\n", ans);
    return 0;
}
