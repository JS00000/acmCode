# include <bits/stdc++.h>

# define pi 3.14159265358979323

using namespace std;

const int N = 1e5 + 1000;

typedef long double ld;

int n;
ld xp,yp,x[N],y[N],lmin,lmax,res,xx,yy,lx,ly,rx,ry,llx,lly,rrx,rry;

ld sqr(ld a)
{
	return a * a;
}

ld cal(ld x,ld y)
{
	return sqr(x-xp) + sqr(y-yp);
}

main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> xp >> yp;
	cin >> x[0] >> y[0];
	lmin = sqr(x[0]-xp) + sqr(y[0]-yp);
	lmax = lmin;
	for (int i=1; i<n; i++)
	{
		cin >> x[i] >> y[i];
		lmin = min(lmin, sqr(x[i]-xp) + sqr(y[i]-yp));
		lmax = max(lmax, sqr(x[i]-xp) + sqr(y[i]-yp));
	}
	x[n]=x[0]; y[n]=y[0];
	for (int i=0; i<n; i++)
	{
		lx = x[i]; rx = x[i+1]; llx = (x[i]+x[i]+x[i+1])/3; rrx = (x[i]+x[i+1]+x[i+1])/3;
		ly = y[i]; ry = y[i+1]; lly = (y[i]+y[i]+y[i+1])/3; rry = (y[i]+y[i+1]+y[i+1])/3;
		for (int test=0; test<100; test++)
		{
			if (cal(llx,lly) > cal(rrx,rry))
			{
				lx = llx;
				ly = lly;
			} else
			{
				rx = rrx;
				ry = rry;
			}
			llx = (lx+lx+rx)/3; rrx = (lx+rx+rx)/3;
			lly = (ly+ly+ry)/3; rry = (ly+ry+ry)/3;
		}
		xx = (lx+rx)/2; yy = (ly+ry)/2;
		lmin = min(lmin, sqr(xx-xp) + sqr(yy-yp));
	}
	res = (lmax - lmin)*pi;
	cout.precision(12);
	cout << fixed << res;
}