#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define maxn 100007
using namespace std;

int n, s, m, t;
int a[maxn];
int h[maxn];
int k[maxn];

void scan_left(int &l, int &ml, double &ans, int &id)
{
    while (l >= 1 && ml && a[l] <= h[0]) {
        if (a[l] < h[id]) {
            h[++id] = a[l];
            k[id] = l--;
        } else if (a[l] == h[id]) {
            k[id] = l--;
        } else {
            while (a[l] > h[id] && ml && id >= 1) {
                int width = k[id-1] - l - 1;
                int height = min(h[id-1], a[l]) - h[id];
                if (ml >= width * height) {
                    if (l < t && t < k[id-1]) ans += height;
                    ml -= width * height;
                } else {
                    if (l < t && t < k[id-1]) ans += double(ml) / width;
                    ml = 0;
                }
                id--;
            }
        }
    }
    if (l == 0) ml = 0;
}

void scan_right(int &r, int &mr, double &ans, int &id)
{
    while (r <= n && mr && a[r] <= h[0]) {
        if (a[r] < h[id]) {
            h[++id] = a[r];
            k[id] = r++;
        } else if (a[r] == h[id]) {
            k[id] = r++;
        } else {
            while (a[r] > h[id] && mr && id >= 1) {
                int width = r - k[id-1] - 1;
                int height = min(h[id-1], a[r]) - h[id];
                if (mr >= width * height) {
                    if (k[id-1] < t && t < r) ans += height;
                    mr -= width * height;
                } else {
                    if (k[id-1] < t && t < r) ans += double(mr) / width;
                    mr = 0;
                }
                id--;
            }
        }
    }
    if (r == n+1) mr = 0;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &s, &m, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i + 1);
    }
    int l = s-1, r = s+1;
    int flow = a[s];
    double ans = 0;
    while (m) {
        while (l >= 1 && a[l] == flow) l--;
        while (r <= n && a[r] == flow) r++;
        if (l >= 1 && r <= n) {
            if (a[l] > flow && a[r] > flow) {
                // valley
                int width = (r-l-1);
                int height = min(a[l], a[r]) - flow;
                if (m >= width * height) {
                    m -= width * height;
                    flow += height;
                } else {
                    flow += m / width;
                    m = 0;
                }
                if (l < t && t < r) ans = flow - a[t];
            } else if (a[l] < flow && a[r] > flow) {
                // hillside left
                int id = 1;
                h[0] = flow;
                k[0] = l+1;
                scan_left(l, m, ans, id);
            } else if (a[l] > flow && a[r] < flow) {
                // hillside right
                int id = 0;
                h[0] = flow;
                k[0] = r-1;
                scan_right(r, m, ans, id);
            } else {
                // ridge
                
                int idl = 0;
                int ml = m / 2;
                h[0] = flow;
                k[0] = l+1;
                scan_left(l, ml, ans, idl);

                int idr = 0;
                int mr = m / 2;
                h[0] = flow;
                k[0] = r-1;
                scan_right(r, mr, ans, idr);

                if (ml == 0 && mr > 0 && l >= 1) {
                    scan_left(l, mr, ans, idl);
                    m = mr;
                } else if (ml > 0 && mr == 0 && r <= n) {
                    scan_right(r, ml, ans, idr);
                    m = ml;
                } else {
                    m = ml + mr;
                }

            }
        } else if (l == 0 && r <= n) {
            // half to right
            int id = 0;
            m /= 2;
            h[0] = flow;
            k[0] = r-1;
            scan_right(r, m, ans, id);
        } else if (l >= 1 && r > n) {
            // half to left
            int id = 0;
            m /= 2;
            h[0] = flow;
            k[0] = l+1;
            scan_left(l, m, ans, id);
        } else {
            // all flow away
            m = 0;
        }
    }
    printf("%d\n", int(ans+1e-8));
    return 0;
}
