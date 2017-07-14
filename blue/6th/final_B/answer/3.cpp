#include <stdio.h>
#define N 100

int connected(int* m, int p, int q)
{
    return m[p]==m[q]? 1 : 0;
}

void link(int* m, int p, int q)
{
    int i;
    if(connected(m,p,q)) return;
    int pID = m[p];
    int qID = m[q];
    for(i=0; i<N; i++) if (m[i] == pID) m[i] = qID;  //填空位置
}

int main()
{
    int m[N];
    int i;
    for(i=0; i<N; i++) m[i] = i; //初始状态，每个节点自成一个连通域
    link(m,0,1); //添加两个账户间的转账关联
    link(m,1,2);
    link(m,3,4);
    link(m,5,6);
    link(m,6,7);
    link(m,8,9);
    link(m,3,7);

    for (int i = 0; i < N; ++i)
        printf("%d ", m[i]);

    printf("%d ", connected(m,4,7));
    printf("%d ", connected(m,4,5));
    printf("%d ", connected(m,7,9));
    printf("%d ", connected(m,9,2));
    return 0;
}
