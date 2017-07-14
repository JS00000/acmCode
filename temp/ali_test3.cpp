#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能*/
/*当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ */
/******************************开始写代码******************************/
int bcz (int b, int c, int d) {
    return (unsigned long long)(pow(b-1+pow(b*b-1, 1./2), c)) % d;
}
/******************************结束写代码******************************/


int main() {
    int res;
    int b, c,  d;
    cin >> b >> c >> d;
    
    res = bcz (b, c, d);
    cout << res << endl;

    return 0;
}