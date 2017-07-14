#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

#define maxn 100010

using namespace std;

int op[maxn];
char s[maxn];
stack<int> sta;

void reverse(string &ret, string &str)
{
    for(int i = str.size() - 1; i >= 0; i--)
        ret.push_back(str[i]);
}
void combine(string &ret, vector<string> &tmp)
{
    for(int i = 0, sz = tmp.size(); i < sz; i++)
    {
        for(int j = 0, len = tmp[i].size(); j < len; j++)
            ret.push_back(tmp[i][j]);
    }
}
void search(string &ret, string &s1, string &s2)
{
    for(int i = 0, sz = s1.size() - s2.size() + 1; i < sz; i++) {
        bool ok = true;
        for(int j = 0, len = s2.size(); j < len; j++)
            if(s1[i + j] != s2[j]) { 
                ok = false; 
                break;
            }
        if(ok) {
            for(int j = i; j < s1.size(); j++) ret.push_back(s1[j]);
            break;
        }
    }
}
string sol(int l, int r)
{
    bool flag = false, start = false;
    string str = "", key = "", ret = "";
    vector<string> tmp;
    for(int i = l + 1; i < r; i++) {
        if(s[i] == '\"') {
            start = start ? false : true;
        } else if(start) {
            str.push_back(s[i]);
        } else if(s[i] == '(') {
            str = sol(i, op[i] + 1);
            i = op[i];
        } else if(s[i] == ' ' || s[i] == ')') {
            if(!flag) flag = true;
            else {
                tmp.push_back(str);
                str = "";
            }
        } else if(!flag) {
            key.push_back(s[i]);
        }
    }
    switch(key[0]) {
        case 'q':
            return tmp[0];
        case 'r':
            reverse(ret, tmp[0]);
            break;
        case 'c':
            combine(ret, tmp);
            break;
        case 's':
            search(ret, tmp[0], tmp[1]);
            break;
    }
    return ret;
}
int main()
{
    gets(s);
    if (s[0] == '\"') {
        printf("%s", s);
        return 0;
    }
    int i;
    bool start = false;
    for(i = 0; s[i]; i++) {
        if(s[i] == '\"') {
            start = start ? false : true;
        }
        if(start) continue;
        if(s[i] == '(') {
            sta.push(i);
        } else if(s[i] == ')') {
            op[sta.top()] = i;
            sta.pop();
        }
    }
    cout << "\"" << sol(0, i) << "\"";
    return 0;
}