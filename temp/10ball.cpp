#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int main()
{
    int cnt = 0;
    for (int a1 = 0; a1 < 3; ++a1)
        for (int a2 = 0; a2 < 3; ++a2)
            for (int a3 = 0; a3 < 3; ++a3)
                for (int a4 = 0; a4 < 3; ++a4)
                    for (int a5 = 0; a5 < 4; ++a5)
                        for (int a6 = 0; a6 < 4; ++a6)
                            for (int a7 = 0; a7 < 4; ++a7)
                                if (a1 + a2 + a3 + a4 + a5 + a6 + a7 == 10)
                                    cnt++;
    printf("%d\n", cnt);
    return 0;
}
