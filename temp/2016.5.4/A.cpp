#include<iostream>
using namespace std;

int main(void)
{
    int Joseph[14]={0};

    int k;
    while(cin>>k)
    {
        if(!k)
            break;

        if(Joseph[k])
        {
            cout<<Joseph[k]<<endl;
            continue;
        }

        int n=2*k;
        int ans[30]={0};


        int m=1;
        for(int i=1;i<=k;i++)
        {
            ans[i]=(ans[i-1]+m-1)%(n-i+1);
//            cout << ans[i] << " ";
            if(ans[i]<k)
            {
//                cout << "       " << m << " fail\n";
                i=0;
                m++;
            }
        }
        Joseph[k]=m;
//        cout << endl;
//        for (int i = 1; i<=k; i++)
//            cout << ans[i] << " ";
        cout<<m<<endl;
    }
    return 0;
}
