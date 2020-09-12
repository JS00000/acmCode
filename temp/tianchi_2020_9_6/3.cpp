#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool judge(string &s1, string &s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    string t1 = s1.substr(1,l1-2);
    string t2 = s2.substr(1,l2-2);
    l1 -= 2;
    l2 -= 2;
    cout << t1 << endl << t2 << endl;
    cout << l1 << " " << l2 << endl;
    if (l1 != l2) return false;
    else if (l1 == 0) return true;
    else {
        bool flag = false;
        for (int i = 0; i < l1; i++) {
            bool p = true;
            for (int j = i; j < i + l1; j++) {
                if (t1[j % l1] != t2[j-i])
                    p = false;
            }
            if (p) flag = true;
        }
        return flag;
    }
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    printf("%s\n", judge(s1, s2) == true ? "true": "false");
    return 0;
}
