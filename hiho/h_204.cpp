#include <cstdio>
#include <cstring>
#define maxn 16

char a[maxn][maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 15; i++) 
            scanf("%s", a[i]);
        int w = 0, b = 0, cw, cb;
        for (int i = 0; i < 15; i++) {
            cw = 0, cb = 0;
            for (int j = 0; j < 15; j++) {
                if (a[i][j] == 'W') cw++, cb = 0;
                else if (a[i][j] == 'B') cw = 0, cb++;
                else cw = cb = 0;
                if (cw == 5) w = 1;
                if (cb == 5) b = 1;
            }
            cw = 0, cb = 0;
            for (int j = 0; j < 15; j++) {
                if (a[j][i] == 'W') cw++, cb = 0;
                else if (a[j][i] == 'B') cw = 0, cb++;
                else cw = cb = 0;
                if (cw == 5) w = 1;
                if (cb == 5) b = 1;
            }
        }
        for (int i = 0; i < 15; i++) {
            cw = 0, cb = 0;
            for (int j = 0; i+j < 15; j++) {
                if (a[i+j][j] == 'W') cw++, cb = 0;
                else if (a[i+j][j] == 'B') cw = 0, cb++;
                else cw = cb = 0;
                if (cw == 5) w = 1;
                if (cb == 5) b = 1;
            }
            cw = 0, cb = 0;
            for (int j = 0; i+j < 15; j++) {
                if (a[i+j][14-j] == 'W') cw++, cb = 0;
                else if (a[i+j][14-j] == 'B') cw = 0, cb++;
                else cw = cb = 0;
                if (cw == 5) w = 1;
                if (cb == 5) b = 1;
            }
        }
        for (int i = 1; i < 15; i++) {
            cw = 0, cb = 0;
            for (int j = 0; i+j < 15; j++) {
                if (a[j][i+j] == 'W') cw++, cb = 0;
                else if (a[j][i+j] == 'B') cw = 0, cb++;
                else cw = cb = 0;
                if (cw == 5) w = 1;
                if (cb == 5) b = 1;
            }
            cw = 0, cb = 0;
            for (int j = 0; i+j < 15; j++) {
                if (a[j][14-i-j] == 'W') cw++, cb = 0;
                else if (a[j][14-i-j] == 'B') cw = 0, cb++;
                else cw = cb = 0;
                if (cw == 5) w = 1;
                if (cb == 5) b = 1;
            }
        }
        if (w && !b) printf("White\n");
        else if (!w && b) printf("Black\n");
        else if (w && b) printf("Both\n");
        else printf("None\n");
    }
    return 0;
}
