#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1007
using namespace std;

struct point
{
	double x, y;
	point() {}
	point(double _x, double _y) {
		x = _x;
		y = _y;
	}
} a[4];

double dist(point &s, point &t) {
	if (s.x == t.x && (s.x == 0 || s.x == 1)) {
		return fabs(s.y-t.y);
	} else if (s.y == t.y && (s.y == 0 || s.y == 1)) {
		return fabs(s.x-t.x);
	} else if (s.x == 0 && t.x == 1 || s.x == 1 && t.x == 0) {
		return 1 + min(s.y+t.y, 2-s.y-t.y);
	} else if (s.y == 0 && t.y == 1 || s.y == 1 && t.y == 0) {
		return 1 + min(s.x+t.x, 2-s.x-t.x);
	} else {
		double mini = 4;
		mini = min(mini, fabs(s.x-0)+fabs(s.y-0)+fabs(t.x-0)+fabs(t.y-0));
		mini = min(mini, fabs(s.x-0)+fabs(s.y-1)+fabs(t.x-0)+fabs(t.y-1));
		mini = min(mini, fabs(s.x-1)+fabs(s.y-0)+fabs(t.x-1)+fabs(t.y-0));
		mini = min(mini, fabs(s.x-1)+fabs(s.y-1)+fabs(t.x-1)+fabs(t.y-1));
		return mini;
	}
}

double f(double x) {
	point p[4];
	p[0].x = x;
	p[0].y = 0;
	p[1].x = 0;
	p[1].y = x;
	p[2].x = 1-x;
	p[2].y = 1;
	p[3].x = 1;
	p[3].y = 1-x;
	double mini = 20;
	int k[4] = {0,1,2,3};
	do {
		mini = min(mini, dist(a[0], p[k[0]]) + dist(a[1], p[k[1]]) + dist(a[2], p[k[2]]) + dist(a[3], p[k[3]]));
	} while ( std::next_permutation(k,k+4) );

	p[0].x = x;
	p[0].y = 0;
	p[1].x = 0;
	p[1].y = 1-x;
	p[2].x = 1-x;
	p[2].y = 1;
	p[3].x = 1;
	p[3].y = x;
	do {
		mini = min(mini, dist(a[0], p[k[0]]) + dist(a[1], p[k[1]]) + dist(a[2], p[k[2]]) + dist(a[3], p[k[3]]));
	} while ( std::next_permutation(k,k+4) );

	return mini;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		double seg[10];
		seg[0] = 0;
		for (int i = 0; i < 4; i++) {
			double x, y;
			scanf("%lf%lf", &x, &y);
			a[i].x = x;
			a[i].y = y;
			// if (x == 0) {
			// 	seg[i+1] = y;
			// } else if (x == 1) {
			// 	seg[i+1] = 1-y;
			// } else if (y == 0) {
			// 	seg[i+1] = x;
			// } else {
			// 	seg[i+1] = 1-x;
			// }
			if (x == 0 || x == 1) {
				seg[i*2+1] = y;
				seg[i*2+2] = 1-y;
			} else {
				seg[i*2+1] = x;
				seg[i*2+2] = 1-x;
			}
		}
		seg[9] = 1;
		sort(seg, seg+10);
		double mini = 20;
		for (int i = 0; i < 9; i++) {
			double l = seg[i], r = seg[i+1], m1, m2;
			double vl = f(l);
			double vr = f(r);
			double vm1, vm2;
			while (r - l > 1e-15) {
				m1 = l + (r - l) / 3;
				m2 = l + (r - l) / 3 * 2;
				vm1 = f(m1);
				vm2 = f(m2);
				if (vm1 < vm2) {
					r = m2;
					vr = vm2;
				} else {
					l = m1;
					vl = vm1;
				}
			}
			mini = min(mini, vl);
		}

		printf("%.12f\n", mini);
	}
	return 0;
}
