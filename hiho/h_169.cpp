// 栈模拟计算器
#include <stack>
#include <string>
#include <cctype>
#include <cstdio>
#include <iostream>

int calculator(const std::string& s)
{
    int n = int(s.size());
    int ret = 0;
    int last = 1;
    char op = '*';
    std::stack<int> stk;
    int num = 0;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (isdigit(c)) {
            num = num * 10 + c - '0';
            continue;
        }
        if (isspace(c)) continue;
        if (c == '+' || c == '-') {
            ret += op == '*' ? last * num : last / num;
            last = c == '+' ? 1 : -1;
            op = '*';
        } else if (c == '*' || c == '/') {
            last = op == '*' ? last * num : last / num;
            op = c;
        } else if (c == '(') {
            stk.push(op);
            stk.push(last);
            stk.push(ret);
            ret = 0;
            last = 1;
            op = '*';
        } else if (c == ')') {
            num = ret + (op == '*' ? last * num : last / num);
            ret = stk.top(); stk.pop();
            last = stk.top(); stk.pop();
            op = stk.top(); stk.pop();
            continue;
        }
        num = 0;
    }
    return ret += op == '*' ? last * num : last / num;
}

int main() 
{
    std::string s;
    std::cin >> s;
    std::cout << calculator(s) << std::endl;
}
