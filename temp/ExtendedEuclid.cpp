#include <stdio.h>
int ExtendedEuclid(int f, int d, int *result);
int main() {
    int x, y, z;
    z = 0;
    printf("输入两个数：\n");
    scanf("%d%d", &x, &y);
    if (ExtendedEuclid(x, y, &z))
        printf("%d和%d互素，乘法的逆元是：%d\n", x, y, z);
    else
        printf("%d和%d不互素，最大公约数为：%d\n", x, y, z);
    return 0;
}

int ExtendedEuclid(int f, int d, int *result) {
    int x1, x2, x3, y1, y2, y3, t1, t2, t3, q;
    x1 = y2 = 1;
    x2 = y1 = 0;
    x3 = (f >= d) ? f : d;
    y3 = (f >= d) ? d : f;
    while (1) {
        if (y3 == 0) {
            *result = x3; /* 两个数不互素则result为两个数的最大公约数，此时返回值为零 */
            return 0;
        }
        if (y3 == 1) {
            *result = y2; /* 两个数互素则resutl为其乘法逆元，此时返回值为1 */
            return 1;
        }
        q = x3 / y3;
        t1 = x1 - q*y1;
        t2 = x2 - q*y2;
        t3 = x3 - q*y3;
        x1 = y1;
        x2 = y2;
        x3 = y3;
        y1 = t1;
        y2 = t2;
        y3 = t3;
    }
}
