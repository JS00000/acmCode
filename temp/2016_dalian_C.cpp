#include <iostream>
#include <time.h>
using namespace std;
class BigInt
{
    private:
        int flag, len, val[5000];
    public:
        BigInt();
        BigInt(const int &n);
        BigInt operator + (const int &n) const;
        BigInt operator - (const int &n) const;
        BigInt& operator = (const int &n);
        BigInt& operator = (const char* n);
        BigInt operator + (const BigInt &b) const;
        BigInt operator - (const BigInt &b) const;

        bool operator < (const BigInt &b) const;
        bool operator < (const int &n) const;
        bool operator == (const BigInt &b) const;
        bool operator == (const int &n) const;
        bool operator <= (const BigInt &b) const;
        bool operator <= (const int &n) const;
        bool operator > (const BigInt &b) const;
        bool operator > (const int &n) const;
        bool operator != (const BigInt &b) const;
        bool operator != (const int &n) const;
        void Print();
        void Println();
        int getLen();
};
int BigInt::getLen()
{
    return this->len;
}
void BigInt::Print()
{
    flag?printf(""):printf("-");
    for (int i=this->len-1;i>=0;i--)
        printf("%d",this->val[i]);
}
void BigInt::Println()
{
    this->Print();
    printf("\n");
}
BigInt::BigInt()
{
    len=0;
    flag=true;
    val[len]=0;
    len++;
}
BigInt::BigInt(const int &n)
{
    int temp(n);
    len=0;
    flag=(n>=0);
    temp=temp>=0?temp:-temp;
    while (temp!=0)
    {
        val[len]=temp%10;
        temp/=10;
        len++;
    }
}
BigInt BigInt::operator + (const BigInt &b) const
{
    BigInt temp;
    BigInt temp1,temp2;
    temp1=*this;
    temp2=b;
    temp1.flag=temp2.flag=true;
    if (this->flag&&!b.flag) {
        temp=temp1-temp2;
        return temp;
    }
    if (!this->flag&&b.flag) {
        temp=temp2-temp1;
        return temp;
    }
    temp.len=b.len>this->len?b.len:this->len;
    for (int i=0;i<temp.len;i++)
    {
        if (i<b.len)
            temp.val[i]=b.val[i];
        else
            temp.val[i]=0;
        if (i<this->len)
            temp.val[i]+=this->val[i];
    }
    for (int i=0;i<temp.len;i++)
        if (temp.val[i]>=10)
        {
            if (i==temp.len-1)
            {
                temp.val[i+1]=1;
                temp.val[i]-=10;
                temp.len++;
            }
            else
            {
                temp.val[i+1]++;
                temp.val[i]-=10;
            }
        }
    temp.flag=this->flag;
    return temp;
}


BigInt BigInt::operator + (const int &n) const
{
    BigInt temp(n);
    return (temp+*this);
}
BigInt BigInt::operator - (const BigInt &b) const
{
    BigInt temp;
    BigInt temp1,temp2;
    temp1=*this;
    temp2=b;
    temp1.flag=temp2.flag=true;
    if (this->flag&&!b.flag) 
    {
        temp=temp1+temp2;
        return temp;
    }
    if (!this->flag&&b.flag)
    {
        temp=temp1+temp2;
        temp.flag=false;
        return temp;
    }
    if (!this->flag&&!b.flag)
    {
        temp1.flag=false;
        temp=temp1+temp2;
        return temp;
    }
    if (*this==b) 
    {
        temp=0;
        return temp;
    }
    if (*this<b)
    {
        temp=(b-(*this));
        temp.flag=false;
        return temp;
    }
    temp=*this;
    for (int i=0;i<b.len;i++)
        temp.val[i]=temp.val[i]-b.val[i];
    for (int i=0;i<temp.len;i++)
    {
        if (temp.val[i]<0)
        {
            temp.val[i]+=10;
            temp.val[i+1]-=1;
        }
        else if (i>=b.len) break;
    }
    while (temp.val[temp.len-1]==0&&temp.len>1)
        temp.len--;
    temp.flag=true;
    return temp;
}
BigInt BigInt::operator - (const int &n) const
{
    BigInt temp;
    temp=n;
    return (*this-temp);
}
bool BigInt::operator < (const BigInt &b) const
{
    if (this->flag&&!b.flag) return false;
    if (!this->flag&&b.flag) return true;
    if (this->len<b.len) return true;
    if (this->len>b.len) return false;
    for (int i=this->len-1;i>=0;i--)
    {
        if (this->val[i]!=b.val[i])
        {
            if (this->val[i]<b.val[i]) return this->flag;
            else return !this->flag;
        }
    }
    return false;
}
bool BigInt::operator < (const int &n) const
{
    BigInt temp;
    temp=n;
    return (*this<temp);
}
bool BigInt::operator == (const BigInt &b) const
{
    if (*this<b) return false;
    if (b<*this) return false;
    return true;
}
bool BigInt::operator == (const int &n) const
{
    BigInt temp;
    temp=n;
    return (*this==temp);
}
bool BigInt::operator <= (const BigInt &b) const
{
    if ((*this<b)||(*this==b)) return true;
    return false;
}
bool BigInt::operator <= (const int &n) const
{
    BigInt temp;
    temp=n;
    return (*this<=temp);
}
bool BigInt::operator > (const BigInt &b) const
{
    return (b<*this);
}
bool BigInt::operator > (const int &n) const
{
    BigInt temp;
    temp=n;
    return (temp<*this);
}
BigInt& BigInt::operator = (const int &n)
{
    int temp;
    temp=n;
    len=0;
    flag=(n>=0);
    temp=temp>=0?temp:-temp;
    while (temp!=0)
    {
        val[len]=temp%10;
        temp/=10;
        len++;
    }
    if (len==0){val[0]=0;len=1;}
    return *this;
}
BigInt&  BigInt::operator = (const char* n)
{
    int j=0;
    int len=strlen(n);
    for (int i=len-1;i>=0;i--)
    {
        this->val[j]=(n[i]-'0')%10;
        j++;
    }
    this->len=j;
    return *this;
}
bool BigInt::operator != (const BigInt &b) const
{
    if (*this<b||b<*this) return true;
    return false;
}
bool BigInt::operator != (const int &n) const
{
    BigInt temp;
    temp=n;
    if (*this!=temp) return true;
    return false;
}
BigInt a[500];
BigInt b[500];
int main()
{
    BigInt n,m;
    a[0]=a[2]=2;
    a[1]=a[3]=3;
    b[0]=b[1]=b[2]=b[3]=1;
    for (int i=4;i<=485;i++)
        a[i]=a[i-1]+a[i-2];
    for (int i=4;i<=485;i++)
        b[i]=b[i-1]+b[i-2];
    char s[100],w[100];
    BigInt temp, we, ha;
    while (scanf("%s%s",s,w)!=EOF)
    {
        n=s; m=w;
        if (n>m)
        {
            temp=m;
            m=n;
            n=temp;
        }
        we=0; ha=m; int j=-1;
        while (a[j+1] <= ha)
        {
                ++j;
                ha = ha - a[j];
                we = we + b[j];
        }
        while(j>=3&&ha!=0)
        {
            if (a[j] <= ha)
            {
                ha = ha - a[j];
                we = we + b[j];
            }
            --j;
        }
        if(ha==0&&n==(m-we)) printf("0\n");
        else printf("1\n");
    }
    return 0;
}