#include<cstring>
#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int x,y,x0,y0;char c; 
bool map[501][501]; 
bool pos_test(const int&xx,const int&yy){
	if(xx<1)return 0;
	if(xx>x)return 0;
	if(yy<1)return 0;
	if(yy>y)return 0;
	return 1;
}
bool inc(){
	c=getc(stdin);
	if(c=='U')return 1;
	if(c=='D')return 1;
	if(c=='L')return 1;
	if(c=='R')return 1;
	return 0;
}
int main(){
	cin>>x>>y>>x0>>y0;
	memset(map,0,sizeof(map));
	int pos=0;string s="";inc();
	while(inc())s+=c;
	for(int i=0;i<s.length();++i){
		if(map[x0][y0])printf("%d ",0);
			else{
				printf("%d ",1);
				map[x0][y0]=true;
				pos++;
				}
		if((s[i]=='U')and(pos_test(x0-1,y0)))--x0;
		if((s[i]=='D')and(pos_test(x0+1,y0)))++x0;
		if((s[i]=='L')and(pos_test(x0,y0-1)))--y0;
		if((s[i]=='R')and(pos_test(x0,y0+1)))++y0;
	}
	printf("%d",x*y-pos);
	return 0;
}
	