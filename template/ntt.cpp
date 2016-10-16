// ntt 暂时不会用
#include <cstdio>
// 998244353原根为3,1004535809原根为3, 786433元根为10, 880803841元根为26.
typedef long long ll;
const int N=262144,K=17;
int n,m,i,k;
int a[N+10],b[N+10],tmp[N+10],tmp2[N+10];
int P=998244353,G=3,g[K+1],ng[K+10],inv[N+10],inv2;
int pow(int a,int b){int t=1;for(;b;b>>=1,a=(ll)a*a%P)if(b&1)t=(ll)t*a%P;return t;}

void NTT(int*a,int n,int t)
{
	for(int i=1,j=0;i<n-1;i++)
	{
		for(int s=n;j^=s>>=1,~j&s;);
		if(i<j){int k=a[i];a[i]=a[j];a[j]=k;}
	}
	for(int d=0;(1<<d)<n;d++)
	{
		int m=1<<d,m2=m<<1,_w=t==1?g[d]:ng[d];
		for(int i=0;i<n;i+=m2)for(int w=1,j=0;j<m;j++)
		{
			int&A=a[i+j+m],&B=a[i+j],t=(ll)w*A%P;
			A=B-t;if(A<0)A+=P;
			B=B+t;if(B>=P)B-=P;
			w=(ll)w*_w%P;
		}
	}
	if(t==-1)for(int i=0,j=inv[n];i<n;i++)a[i]=(ll)a[i]*j%P;
}

//给定a,求a的逆元b
void getinv(int*a,int*b,int n)
{
	if(n==1){b[0]=pow(a[0],P-2);return;}
	getinv(a,b,n>>1);
	int k=n<<1,i;
	for(i=0;i<n;i++)tmp[i]=a[i];
	for(i=n;i<k;i++)tmp[i]=b[i]=0;
	NTT(tmp,k,1),NTT(b,k,1);
	for(i=0;i<k;i++){
	b[i]=(ll)b[i]*(2-(ll)tmp[i]*b[i]%P)%P;
	if(b[i]<0)b[i]+=P;
	}
	NTT(b,k,-1);
	for(i=n;i<k;i++)b[i]=0;
}

//给定a,求a的对数函数，且a[0]=1
void getln(int*a,int*b,int n)
{
	getinv(a,tmp2,n);
	int k=n<<1,i;
	for(i=0;i<n-1;i++)b[i]=(ll)a[i+1]*(i+1)%P;
	for(i=n-1;i<k;i++)b[i]=0;
	NTT(b,k,1),NTT(tmp2,k,1);
	for(i=0;i<k;i++)b[i]=(ll)b[i]*tmp2[i]%P;
	NTT(b,k,1);
	for(i=n-1;i;i--)b[i]=(ll)b[i-1]*inv[i]%P;b[0]=0;
}

//给定a,求a的指数函数，且a[0]=0
void getexp(int*a,int*b,int n)
{
	if(n==1){b[0]=1;return;}
	getexp(a,b,n>>1);
	getln(b,tmp,n);
	int k=n<<1,i;
	for(i=0;i<n;i++){tmp[i]=a[i]-tmp[i];if(tmp[i]<0)tmp[i]+=P;}
	if((++tmp[0])==P)tmp[0]=0;
	for(i=n;i<k;i++)tmp[i]=b[i]=0;
	NTT(tmp,k,1),NTT(b,k,1);
	for(i=0;i<k;i++)b[i]=(ll)b[i]*tmp[i]%P;
	NTT(b,k,-1);
	for(i=n;i<k;i++)b[i]=0;
}

//给定a,求a的平方根，b且a[0]=1
void getroot(int*a,int*b,int n)
{
	if(n==1){b[0]=1;return;}
	getroot(a,b,n>>1);
	getinv(b,tmp2,n);
	int k=n<<1,i;
	for(i=0;i<n;i++)tmp[i]=a[i];
	for(i=n;i<k;i++)tmp[i]=b[i]=0;
	NTT(tmp,k,1),NTT(b,k,1),NTT(tmp2,k,1);
	for(i=0;i<k;i++)b[i]=((ll)b[i]*b[i]+tmp[i])%P*inv2%P*tmp2[i]%P;
	NTT(b,k,-1);
	for(i=n;i<k;i++)b[i]=0;
}

int main(int argc, char const *argv[])
{
	for(g[K]=pow(G,(P-1)/N),ng[K]=pow(g[K],P-2),i=K-1;~i;i--)
		g[i]=(ll)g[i+1]*g[i+1]%P,ng[i]=(ll)ng[i+1]*ng[i+1]%P;
	for(inv[1]=1,i=2;i<=N;i++)inv[i]=(ll)(P-inv[P%i])*(P/i)%P;inv2=inv[2];
	scanf("%d%d",&n,&m);
	for(k=1;k<=n;k<<=1);
	for(i=0;i<=n;i++)scanf("%d",&a[i]);
	// getln(a,b,k);
	getroot(a,b,k);
	for(i=0;i<k;i++)printf("%d ",b[i]);
	// for(i=0;i<k;i++)b[i]=(ll)b[i]*m%P;
	// getexp(b,a,k);
	// for(i=0;i<k;i++)printf("%d ",a[i]);
}
