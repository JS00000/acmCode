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

    BigInteger(int number = 0) :length(number) {
        assert(0 <= number && number <= BASE);
        memset(digit, 0, sizeof(digit));
        digit[0] = number;
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
    for(int i = 0; i < a.length; ++i) {
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return false;
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
    return res;
}


int vis[35][35];
BigInteger p[35][35];
inline void solve(int n, int m)
{
    if(vis[n][m]) {
        p[n][m].output();
        return ;
    }
    vis[n][m] = 1;
    BigInteger ans = 0, tmp = m;
    ans.normalize();
    tmp.normalize();
    ans = ans + (tmp ^ (n * n)) + (tmp ^ ((n * n + 3) / 4)) * 2 + (tmp ^ ((n * n + 1) / 2));
    //考虑翻转和旋转
    if(n & 1) {
        ans = ans + (tmp ^ ((n * n - n) / 2 + n)) * 2; //沿中间线翻转
        ans = ans + (tmp ^ ((n * n - n) / 2 + n)) * 2; //沿对角线翻转
    }else {
        ans = ans + (tmp ^ (n * n / 2)) * 2; //沿中间线翻转
        ans = ans + (tmp ^ ((n * n - n) / 2 + n)) * 2; //沿对角线翻转
    }
    ans = ans / 8;
    ans.output();
    p[n][m] = ans;
}

int main()
{
    int n, m;
    memset(vis, 0, sizeof(vis));
    while(~scanf("%d%d", &n, &m)) {
        solve(n, m);
    }
    return 0;
}