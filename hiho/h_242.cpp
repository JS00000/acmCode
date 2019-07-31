#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 20
using namespace std;

int N;
int c[maxn];
bitset<256> pattern[maxn];

bool check(int x, int y, int lx, int ly)
{
    if (x == lx) {

    } else if (y == ly) {

    } else if (lx - x == ly - y && abs(lx - x) > 1) {

    } else if (lx - x == y - ly && abs(lx - x) > 1) {

    }
    return 0;
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int t;
        int x, y, lx = 0, ly = 0, sx, sy, dx, dy;
        scanf("%d%d", &t, c+i);
        for (int j = 0; j < t; j++) {
            scanf("%d%d", &x, &y);
            if (lx > 0 && ly > 0) {
                if (x == lx && abs(ly-y) > 1) {
                    for (int ty = min(y, ly); ty < max(y, ly); ty++) {
                        pattern[i] |= ((x-1)*4+ty)*((lx-1)*4+ty+1);
                    }
                } else if (y == ly && abs(lx-x) > 1) {
                    for (int tx = min(x, lx); tx < max(x, lx); tx++) {
                        pattern[i] |= ((tx-1)*4+y)*(tx*4+ly);
                    }
                } else if (lx - x == ly - y && abs(lx - x) > 1) {
                    for (int tx = min(x, lx), ty = min(y, ly); tx < max(x, lx); tx++, ty++) {
                        pattern[i] |= ((tx-1)*4+ty)*(tx*4+ly+1);
                    }
                } else if (lx - x == y - ly && abs(lx - x) > 1) {
                    for (int tx = min(x, lx), ty = max(y, ly); tx < max(x, lx); tx++, ty--) {
                        pattern[i] |= ((tx-1)*4+ty)*(tx*4+ty-1);
                    }
                } else {
                    pattern[i] |= ((x-1)*4+y)*((lx-1)*4+ly);
                }
            } else {
                sx = x;
                sy = y;
            }
            lx = x;
            ly = y;
        }
        dx = x;
        dy = y;
    }
    
    return 0;
}
