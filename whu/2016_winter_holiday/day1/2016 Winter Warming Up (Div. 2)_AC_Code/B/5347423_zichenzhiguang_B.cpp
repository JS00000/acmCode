#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 100010;
int s[510][510];
char o[maxn];
int main()
{
    int x, y;
    int x0, y0;
    cin >> x >> y >> x0 >> y0;
    while(getchar() != '\n') continue;
    scanf("%s", o);
    while(getchar() != '\n') continue;
    int len = strlen(o);
    int x_ = x0, y_ = y0;
    int sum = 0;
    memset(s, 1, sizeof(s));
    int index = 0;
    while(index < len) {
        if(s[x_][y_]) { s[x_][y_] = 0; sum++; printf("1 "); }
        else printf("0 ");
        switch(o[index]) {
        case 'U':
            if(x_-1 > 0)
                x_--;
            break;
        case 'D':
            if(x_+1 <= x)
                x_++;
            break;
        case 'L':
            if(y_-1 > 0)
                y_--;
            break;
        case 'R':
            if(y_+1 <= y)
                y_++;
            break;
        }
        index++;
    }
    printf("%d\n", x*y-sum);
    return 0;
}
