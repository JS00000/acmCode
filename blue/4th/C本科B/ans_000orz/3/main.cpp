#include <iostream>

using namespace std;

long long ans = 0;
void dfs(int step, int h)
{
    if(h==39&&step%2==0)
    {
        ans++;
        return;
    }
    else if(h<39)
    {
        dfs(step+1,h+1);
        dfs(step+1,h+2);
    }
}

int main()
{
    dfs(0,0);
    cout << ans << endl;
    return 0;
}
