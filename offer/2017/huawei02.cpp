#include <stack>
#include <string>
#include <iostream>

using namespace std;

stack<string> sta;

int main()
{
    std::ios::sync_with_stdio(false);
    string str;
    while (cin >> str) sta.push(str);
    if (!sta.empty()) {
        cout << sta.top(), sta.pop();
        while (!sta.empty()) cout << " " << sta.top(), sta.pop();
    }
    return 0;
}
