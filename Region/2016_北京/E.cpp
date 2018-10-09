#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char input[6];
int digits[6];
char s2[16][6] = {  "00000", "00001", "00010", "00100", 
                    "01000", "10000", "00011", "00101", 
                    "01001", "10001", "00110", "01010", 
                    "10010", "01100", "10100", "11000"};
char s3[26][6] = {  "00000", "00001", "00010", "00100", 
                    "01000", "10000", "00011", "00101", 
                    "01001", "10001", "00110", "01010", 
                    "10010", "01100", "10100", "11000", 
                    "00111", "01011", "01101", "01110", 
                    "10011", "10101", "10110", "11001", 
                    "11010", "11100"};



bool check()
{
    bool c[5], ret = 1;
    for (int i = 0; i < 5; i++) c[i] = 0;
    for (int i = 0; i < 5; i++) c[digits[i]-'1'] = 1;
    for (int i = 0; i < 5; i++) if (!c[i]) ret = 0;
    return ret;
}

int op1()
{
    int ret = 0;

    return ret;
}

int op2(int x)
{
    int ret = 0;
    for (int i = 0; i < 5; i++) {
        if (s2[x][i] == '1') {
            digits[i] = (digits[i] - '0' + 1) % 10 + '0';
            ret++;
        }
    }
    return ret;
}

int op3()
{
    int temp, mini = 10000;
    for (int x = 0; x < 26; x++) {
        for (int i = 0; i < 5; i++) {
            if (s3[x][i] == '1') {
                temp++;
                
            }
        }
    }
    return mini;
}

int main()
{
    while (~scanf("%s", input)) {
        for (int i = 0; i < 5; i++) digits[i] = input[i] - '0';
        int temp = op3();
        if (temp < 10000) printf("%d\n", temp);
        else printf("-1\n");
    }
    return 0;
}
