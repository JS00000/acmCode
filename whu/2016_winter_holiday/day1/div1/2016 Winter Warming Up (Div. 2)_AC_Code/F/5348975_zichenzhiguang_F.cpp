#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 1100;
int s[maxn][maxn];
int main()
{
    int k;
    cin >> k;
    if(k == 0) {
        printf("+\n");
        return 0;
    }
    s[0][0] = 1; s[0][1] = 1;
    s[1][0] = 1; s[1][1] = -1;
    int i;
    for(i = 2; i < pow(2, k); i *= 2) {
        for(int j = 0; j < i; j++) {
            for(int k = i; k < 2*i; k++) {
                if(j < i/2) s[j][k] = -s[j][k-i];
                else s[j][k] = s[j][k-i];
            }
        }
        for(int j = i; j < 2*i; j++) {
            for(int k = 0; k < i; k++) {
                s[j][k] = s[j-i][k];
            }
        }
        for(int j = i; j < 2*i; j++) {
            for(int k = i; k < 2*i; k++) {
                if(j-i < i/2) s[j][k] = s[j-i][k-i];
                else s[j][k] = -s[j-i][k-i];
            }
        }
    }
    for(int j = 0; j < i; j++) {
        for(int k = 0; k < i; k++)
        if(s[j][k] > 0) printf("+");
        else printf("*");
        printf("\n");
    }
    return 0;
}
