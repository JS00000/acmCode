// fft
#include <cstdio>
#include <ctime>
#include <complex>
#include <iostream>
#include <algorithm>
#define maxn 100007
using namespace std;
typedef std::complex<double> complex_t;
int n, bit_length;
complex_t epsilon[maxn];
complex_t arti_epsilon[maxn];
complex_t A[maxn];
complex_t B[maxn];
complex_t temp[maxn];
void fft(int n, complex_t* buffer, int offset, int step, complex_t* epsilon)
{
    if(n == 1) return;
    int m = n >> 1;
    fft(m, buffer, offset, step << 1, epsilon);
    fft(m, buffer, offset + step, step << 1, epsilon);
    for(int k = 0; k != m; ++k)
    {
        int pos = 2 * step * k;
        temp[k] = buffer[pos + offset] + epsilon[k * step] * buffer[pos + offset + step];
        temp[k + m] = buffer[pos + offset] - epsilon[k * step] * buffer[pos + offset + step];
    }
    for(int i = 0; i != n; ++i)
        buffer[i * step + offset] = temp[i];
}

void init_epsilon(int n)
{
    double pi = acos(-1);
    for(int i = 0; i != n; ++i)
    {
        epsilon[i] = complex_t(cos(2.0 * pi * i / n), sin(2.0 * pi * i / n)); 
        arti_epsilon[i] = conj(epsilon[i]);
    }
}

/* 这时候 n 已经补齐到 2 的幂次 */
void transform(int n, complex_t *x, complex_t *w)
{
    for(int i = 0, j = 0; i != n; ++i)
    {
        if(i > j) swap(x[i], x[j]);
        for(int l = n >> 1; (j ^= l) < l; l >>= 1);
    }
    for(int i = 2; i <= n; i <<= 1)
    {
        int m = i >> 1;
        for(int j = 0; j < n; j += i)
        {
            for(int k = 0; k != m; ++k)
            {
                complex_t z = x[j + m + k] * w[n / i * k];
                x[j + m + k] = x[j + k] - z;
                x[j + k] += z;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    n = 32;
    init_epsilon(n);
    for (int i = 0; i < n; ++i)
        A[i] = complex_t(i, 0);
    time_t beg, end;
    beg = clock();
    fft(n, A, 0, 1, epsilon);
    end = clock();

    for (int i = 0; i < n; ++i)
        cout << A[i] << endl;
    cout << endl;

    std::cout << "Time: " << end-beg << std::endl;

    for (int i = 0; i < n; ++i)
        A[i] = complex_t(i, 0);
    beg = clock();
    transform(n, A, epsilon);
    end = clock();
    for (int i = 0; i < n; ++i)
        cout << A[i] << endl;
    std::cout << "Time: " << end-beg << std::endl;
    return 0;
}
