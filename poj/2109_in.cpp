// 大数类
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int BASE = 1000;
const int SIZE = 510;


struct BigInteger{
    int length, digit[SIZE];
    BigInteger(ll number = 0) {
        assert(0 <= number);
        memset(digit, 0, sizeof(digit));
        for (length = 0; number; length++, number/=BASE) digit[length] = number%BASE;
        this->normalize();
    }
    // BASE = 1000
    BigInteger(char *p) {
        memset(digit, 0, sizeof(digit));
        int len = strlen(p);
        length = (len-1)/3;
        for (int i = 0; i < (len-1)%3+1; i++, p++) digit[length] = digit[length]*10 + *p - '0';
        for (int i = length-1; i >= 0; i--)
            for (int j = 0; j < 3; j++, p++) digit[i] = digit[i] * 10 + *p - '0';
        length++;
        this->normalize();
    }
    BigInteger normalize() {
        while(length && digit[length - 1] == 0) length--;
        return *this;
    }
    int operator [](int index) const {
        return digit[index];
    }
    int& operator [](int index) {
        return digit[index];
    }
    void output() {
        printf("%d", digit[length - 1]);
        for(int i = length - 2; i >= 0; i--) {
            printf("%03d", digit[i]);
        }
        printf("\n");
    }
};

inline bool operator < (const BigInteger& a, const BigInteger& b)
{
    if(a.length != b.length) return a.length < b.length;
    for(int i = a.length - 1; i >= 0; i--)
        if(a[i] != b[i]) return a[i] < b[i];
    return false;
}

inline bool operator <= (const BigInteger& a, const BigInteger& b)
{
    if(a.length != b.length) return a.length < b.length;
    for(int i = a.length - 1; i >= 0; i--)
        if(a[i] != b[i]) return a[i] < b[i];
    return true;
}


inline bool operator == (const BigInteger& a, const BigInteger& b)
{
    if (a.length != b.length) return false;
    for (int i = a.length - 1; i >= 0; i--)
        if (a.digit[i] != b.digit[i]) return false;
    return true;
}

inline BigInteger operator + (const BigInteger& a, const BigInteger& b)
{
    BigInteger c;
    c.length = max(a.length, b.length) + 1;
    for(int i = 0, carry = 0; i < c.length; ++i) {
        carry += a[i] + b[i];
        c[i] = carry % BASE;
        carry /= BASE;
    }
    return c.normalize();
}

inline BigInteger operator - (const BigInteger& a, int b)
{
    assert(0 <= b && b < BASE);
    BigInteger c;
    c.length = a.length;
    for(int i = 0, carry = -b; i < a.length; ++i) {
        carry += a[i];
        c[i] = carry;
        if(c[i] < 0) {
            c[i] += BASE;
            carry = -1;
        }else carry = 0;
    }
    return c.normalize();
}

inline BigInteger operator * (const BigInteger& a, const BigInteger& b)
{
    BigInteger c;
    c.length = a.length + b.length;
    for(int i = 0; i < a.length; ++i) {
        for(int j = 0, carry = 0; j <= b.length; ++j) {
            carry += a[i] * b[j] + c[i + j];
            c[i + j] = carry % BASE;
            carry /= BASE;
        }
    }
    return c.normalize();
}

inline BigInteger operator / (const BigInteger& a, int b)
{
    assert(0 <= b && b < BASE);
    BigInteger c;
    c.length = a.length;
    for(int i = c.length - 1, carry = 0; i >= 0; i--) {
        carry = carry * BASE + a[i];
        c[i] = carry / b;
        carry %= b;
    }
    return c.normalize();
}

inline BigInteger operator ^ (const BigInteger& a, int b)
{
    BigInteger res = 1, tmp = a;
    while(b) {
        if(b & 1) res = res * tmp;
        tmp = tmp * tmp;
        b >>= 1;
    }
    return res.normalize();
}


void solve(int n, char p[])
{
    if (n == 1) printf("%s\n", p);
    else
    {
        BigInteger ans(p);
        ll len = (strlen(p)-1)/n+1, l, r, mid;
        BigInteger ret;
        l = pow(10, len-1);
        r = pow(10, len)-1;
        while(l < r)
        {
            mid = (l+r)/2;
            ret = BigInteger(mid) ^ n;
            if (ret < ans) l = mid+1;
            else r = mid;
        }
        printf("%lld\n", l);
    }
}

int main()
{
	freopen("2109.in", "w", stdout);
    int n;
    // char p[200];
    // while(~scanf("%d%s", &n, p)) {
        // solve(n, p);
    // }
    for (int i = 1; i <= 20; i++)
    {
    	for (int j = 1; j <= 100; j++ )
    	{
    		printf("%d %d ", i, j);
    		(BigInteger(i) ^ j).output();
    	}
    }
    return 0;
}
