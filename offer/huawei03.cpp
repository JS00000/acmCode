#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string del_space(string str)
{
    int f = 0, r = str.length() - 1;
    while (f < str.length() && str[f] == ' ') f++;
    while (r >= 0 && str[r] == ' ') r--;
    if (r < 0) return "\"\"";
    return str.substr(f, r - f + 1);
}

vector<string> get_para(string str)
{
    vector<string> vec;
    int i = 0;
    while (i < str.length()) {
        while (str[i] == ' ') i++;
        if (str[i] == '\"') {
            int j = i++;
            while (str[i] != '\"') i++;
            vec.push_back(str.substr(j, i-j+1));
        } else {
            // 还要加个stack
            int j = i++;
            bool instr = 0;
            while (str[i] != ')' || instr) {
                if (instr && str[i] == '\"') instr = 0;
                if (!instr && str[i] == '\"') instr = 1;
                i++;
            }
            vec.push_back(str.substr(j, i-j+1));
        }
        i++;
    }
    return vec;
}

string solve(string str)
{
    str = del_space(str);
    if (str[0] == '\"') return str;
    else {
        int f = 1;
        while (str[f] == ' ') f++;
        if (str[f] == 'q') {
            return solve(str.substr(6+f, str.length()-7-f));
        } else if (str[f] == 'r') {
            str = solve(str.substr(8+f, str.length()-9-f));
            reverse(str.begin(), str.end());
            return str;
        } else if (str[f] == 's') {
            // vector<string> para = get_para(str.substr(7+f, str.length()-8-f));

        } else if (str[f] == 'c') {
            // vector<string> para = get_para(str.substr(8+f, str.length()-9-f));
        }
    } 
    return "\"\"";
}

int main()
{
    string str;
    getline(cin,str);
    cout << solve(str);
    return 0;
}
