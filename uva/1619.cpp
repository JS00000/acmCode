// 单调栈
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100005
#define LL long long
int a[N] , n , top , _stack[N] , st[N] , en[N];
LL maxn , sum[N];
int main()
{
    bool flag = 1;
    while(~scanf("%d" , &n)){
        if (flag) flag = 0;
        else printf("\n");
        for(int i=1 ; i<=n ; i++) scanf("%d" , &a[i]);
        sum[1] =  _stack[1] = maxn = a[1] , top=1 , st[1] = en[1] = 1;
        a[++n] = -1;
        int ansst = 1 , ansen = 1;
        for(int i=2 ; i<=n ; i++){
            LL tmp = sum[top];
            int curst = i , curen = en[top];
            while(top && a[i]<=_stack[top]){
                if(maxn<(tmp-sum[top-1])*_stack[top]){
                    maxn = (tmp-sum[top-1])*_stack[top];
                    ansst = st[top] , ansen = curen;
                }
                curst = st[top] ;
                top--;
            }
            _stack[++top] = a[i];
            sum[top]= tmp+_stack[top];
            st[top] =curst , en[top] = i;
        }
        printf("%lld\n%d %d\n" , maxn , ansst , ansen);
    }
    return 0;
}