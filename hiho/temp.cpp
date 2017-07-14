#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;



int main()
{
    int a = 2e9;
    printf("%d\n", a);
    for (int i = 0; i < 10; ++i)
    {
        int b[1000] = {};
        for (int j = 0; j < 1000; ++j)
        {
            if (b[j]) printf("%d ", b[j]);
        }
    }
    return 0;
}
