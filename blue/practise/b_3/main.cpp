#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
const double PI = atan(1.0)*4;

int main()
{
    int r;
    cin >> r;
    cout.setf(ios::fixed);
    cout << setprecision(7) << r*r*PI << endl;
    return 0;
}
