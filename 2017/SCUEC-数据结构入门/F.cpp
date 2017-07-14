#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int ra(char c)
{
    if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    else return 0;
}

double calc(double a, double b, char c)
{
    if (c == '+') return a + b;
    else if (c == '-') return a - b;
    else if (c == '*') return a * b;
    else if (c == '/') return a / b;
    else return b;
}

char s[maxn];
char sc[maxn];
double sn[maxn];

int main()
{
    int kn = 0, kc = 0;
    while(gets(s), s[0] != '0' || s[1] != '\0')
    {
        int len = strlen(s);
        s[len] = '#';
        for (int i = 0; i <= len; ++i)
        {
            if (s[i] == ' ') continue;
            else if (s[i] >= '0' && s[i] <= '9')
            {
                int n = s[i] - '0';
                while(++i, s[i] >= '0' && s[i] <= '9') n = n*10 + s[i] - '0';
                sn[++kn] = n;
                i--;
            }
            else
            {
                while(kc > 0 && ra(sc[kc]) >= ra(s[i])) sn[kn-1] = calc(sn[kn-1], sn[kn], sc[kc]), kn--, kc--;
                sc[++kc] = s[i];
            }
        }
        printf("%.2f\n", sn[1]);
    }
    return 0;
}
