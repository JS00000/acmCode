#include <iostream>


using namespace std;

int main(int argc, char *argv[])
{
    int T,a,b,m,x,y,t;
    bool p[2010];
    cin >> T;
    while(T--)
    {
     cin >> a >> b >> m;
     for (int i = 0; i<m ; i++) p[i] = 0;
     p[a] = 1;
     p[b] = 1;
     x = b;
     y = (a+b)%m;
     while(!(x==a&&y==b))
     {
      t = x;
      x = y;
      y = (t+x)%m;
      p[x] = 1;
      p[y] = 1;                 
     }
     int ans = 0;
     for   (int i = 0;i<m; i++)
     {
           if (p[i]) ans++;
     }
     cout << ans << endl;
    }
    return 0;
}
