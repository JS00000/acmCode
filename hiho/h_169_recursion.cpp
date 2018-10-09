// 递归实现计算器
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MAX(a,b) ((a)>=(b)?(a):(b))
#define MIN(a,b) ((a)<=(b)?(a):(b))
#define OO 0x0fffffff
using namespace std;
typedef long long LL;
const int N = 128;
char str[N];
int cal(int s,int e){
     int number=0; bool isAnum=true;
     for(int i=s;i<e;i++){
         if(str[i]<'0'||str[i]>'9') {isAnum=false;break;}
         number=number*10+str[i]-'0';
     }
     if(isAnum) return number;

     int cnt=0;
     int lv1=-1,lv2=-1;
     for(int i=s;i<e;i++){
        switch(str[i]){
           case '(':cnt++; break;
           case ')':cnt--; break;
           case '+':case '-': if(!cnt) lv1=i;break;
           case '*':case '/': if(!cnt) lv2=i;break;
        }
     }
     if(lv1<0) lv1=lv2;
     if(lv1<0) return cal(s+1,e-1);
     switch (str[lv1]){
         case '+' : return cal(s,lv1) + cal(lv1+1,e);
         case '-' : return cal(s,lv1) - cal(lv1+1,e);
         case '*' : return cal(s,lv1) * cal(lv1+1,e);
         case '/' : return cal(s,lv1) / cal(lv1+1,e);
     }
     return 0;
}
int main(){
    scanf("%s",str);
    printf("%d\n",cal(0,strlen(str)));
    return 0;
}
