#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b,c,d,e,ans = 0;
    for(a = 1;a<10;a++)
    {
        for(b = 1;b<10;b++)
        {
            if(a==b) continue;
            for(c = 1;c<10;c++)
            {
                if(a==c||b==c) continue;
                for(d = 1;d<10;d++)
                {
                    if(a==d||b==d||c==d) continue;
                    for(e = 1;e<10;e++)
                    {
                        if(a==e||b==e||c==e||d==e) continue;
                        if((a*10+b)*(c*100+d*10+e)==(a*100+d*10+b)*(c*10+e)) ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
