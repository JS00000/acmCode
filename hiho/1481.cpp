#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;



int main()
{
    int T;
    char s[110];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s);
        int len = strlen(s);
        bool p = 0;
        int ca = 0, cl = 0;
        for (int i = 0; i < len; ++i)
        {
            if (s[i] == 'L') cl++;
            else if (s[i] == 'A') ca++, cl = 0;
            else cl = 0;
            if (ca > 1 || cl > 2)
            {
                p = 1;
                break;
            }
        }
        printf("%s\n", p?"NO":"YES");
    }
    return 0;
}
