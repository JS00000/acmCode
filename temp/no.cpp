#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

int main()
{
    for (int i = 1; i <= 6; i++) {
        switch (i%5) {
            case 0: printf("*"); break;
            case 1: printf("#"); break;
            default: printf("*");
            case 2: printf("\n"); break;
        }
    }
    return 0;
}

// 2. 1/2+2/3+3/5+5/8...
// 3. 
// 4. 分子分母

