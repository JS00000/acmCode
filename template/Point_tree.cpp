// PointTree
#include <stdio.h>
#include <string.h>

template < int N > // 表示可用区间为[0,N)，其中N必须是2的幂数;
class PointTree {
    int a[ 2 * N];
    int size;
public:
    void clear() { memset( this , 0 , sizeof ( * this ));}
    void add( int n)
    {
        int i = N + n; ++ size;
        for (;i > 1 ; i /= 2 )
            if ( ~ i & 1 ) a[i/ 2] ++ ;//偶数
    }
    int cntLs( int n) { // 统计小于
        int i = N + n,c = 0 ; // 若统计小于等于则c=a;
        for (; i > 1 ; i /= 2 )
            if (i & 1 ) c += a[i / 2 ];//奇数
        return c;
    }
    int cntGt( int n) { return size - a[N + n] - cntLs(n); }
    void del(int n){
        if(!a[n+=N])return;
        --size;
        for(--a[n]; n>1; n/=2)
            if(~n&1)--a[n/2];
    }
};

PointTree<256> t;

int main()
{
    char p[20]="13654287";
    int x=0;
    for(int i=0;i<strlen(p);i++)
    {
        x+=t.cntGt(p[i]-'0');
        t.add(p[i]-'0');
    }
    printf("%d\n",x);
    return 0;
}
