// 数学
#include "iostream"
#include "ctime"


using namespace std;

const int MOD = 1e9+7;

typedef long long LL;

LL mul_mod(LL a, LL b)
{
	LL res = 0;
	int flag;
	if ( b < 0 ) 
	{
		flag = 1;
		b = -b;
	}
	else flag = 0;
	while(b)
	{
		if (b & 1)
			res = (res + a) % MOD;
		b >>= 1;
		a = (a << 1) % MOD;
	}
	res %= MOD;
	return (flag ? (~res + 1) : res);
}


long pow(long a, long b, long n)
{
	long base = a;
	long r = 1;
	while(b!=0)
	{
		if (b&1) r=r*base%n;
		base=base*base%n;
		b>>=1;
	}
	return r;
}

ll exgcd(ll a,ll b,ll &x,ll &y)  //返回最大公约数，x，y存的是一组解
{
    if(b==0)
    {
        x=1 , y=0;
        return a;
    }
    ll r=exgcd( b , a % b , y , x );
    y -= x * (a/b);
    return r;
}

LL inv(LL a,LL m)
{
    LL d,x,y;
    d = exgcd( a , m , x , y );
    return d==1 ? (x%m+m)%m : -1;  //-1无解
}



int main(int argc, char const *argv[])
{
	/* code */
	clock_t start, finish;
	start = clock();
	
	// cout << pow(26, 11, 1000000007);

	LL temp;
	LL sum = 0;
	for (LL i = 0x0fffffffff0fff; i < 0x0fffffffffffff; ++i)
	{
		// cout << ~i << endl;
		// temp = mul_mod(i, -i);
		temp = (i*-i)%MOD;
		// if ((i*-i)%MOD != mul_mod(i, -i))
		// {
			// sum++;
		// }
	}
	cout << sum << endl;
	// long r = 1;
	// for (int i = 0; i < 10000; ++i)
	// {
	// 	r = r*2%1000000;
	// }
	// cout << r;

	finish = clock();
	cout << "\nTime:" << double(finish - start) << endl;
	return 0;
}