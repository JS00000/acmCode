#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int a[60][10];
    int n, m, stu;
    double x, y;
    double b[60], c[10];
    cout.precision(2);
    cout.setf(ios::fixed);
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            x = 0;
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                x += a[i][j];
            }
            b[i] = x/m;
        }
        for (int i = 0; i < m; i++)
        {
            y = 0;
            for (int j = 0; j < n; j++)
            {
                 y += a[j][i];
            }
            c[i] = y/n;
        }
        stu = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] < c[j])
                {
                    stu--;
                    break;
                }
            }
        }
        for (int i = 0; i < n-1; i++)
            cout << b[i] << " ";
        cout  << b[n-1] << endl;
        for (int i = 0; i < m-1; i++)
            cout << c[i] << " ";
        cout << c[m-1] << endl;
        cout << stu << "\n\n";
    }
    return 0;
}
