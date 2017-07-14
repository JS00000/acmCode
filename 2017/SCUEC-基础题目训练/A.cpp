#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;



int main()
{
    int n;
    scanf("%d", &n);
    char s[100];
    while(n--)
    {
        scanf("%s", s);
        int len = strlen(s);
        if (len > 16 || len < 8) printf("NO\n");
        else
        {
            bool td[4] = {0, 0, 0, 0};
            for (int i = 0; i < len; ++i)
                if (s[i] >= '0' && s[i] <= '9') td[0] = 1;
                else if (s[i] >= 'a' && s[i] <= 'z') td[1] = 1;
                else if (s[i] >= 'A' && s[i] <= 'Z') td[2] = 1;
                else td[3] = 1;
            int sum = 0;
            for (int i = 0; i < 4; ++i) sum += td[i];
            if (sum < 3) printf("NO\n");
            else printf("YES\n");
        }
    }
    return 0;
}
