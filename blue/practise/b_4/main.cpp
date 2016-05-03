#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n==1)
    {
        cout << "1\n" << endl;
    }
    else if (n==2)
    {
        cout << "1\n" << endl;
    }
    else
    {
        int a=1,b=1,t;
        for (int i = 2; i < n; i++)
        {
            t = a;
            a = b;
            b = (a+t)%10007;
        }
        cout << b << endl;
    }
    return 0;
}
