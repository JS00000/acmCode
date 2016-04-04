#include<cstdio>
using namespace std;
int main(){
	int a[3],b[3];int sol=0;
	scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2]);
	for(int i=0;i<=2;i++){
		if(a[i]>=b[i]){
			sol+=(a[i]-b[i])/2;
		}
		else{
			sol+=a[i]-b[i];
		}
	}
	if(sol>=0)printf("Yes");
	if(sol<0)printf("No");
	return 0;
} 