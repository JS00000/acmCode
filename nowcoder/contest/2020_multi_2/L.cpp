#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    if (s.substr(0, 6) == "lovely") {
        cout << "lovely" << endl;
    } else {
        cout << "ugly" << endl;
    }
    return 0;
}
