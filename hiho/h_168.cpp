#include <set>
#include <string>
#include <cstdio>
#include <algorithm>
#define maxn 1007
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    string temp, t;
    while (n) {
        temp.push_back('0' + n % 2);
        n = n >> 1;
    }
    int ans = 1, size = temp.length();
    set<string> s;
    s.insert(temp);
    while (!s.empty()) {
        temp = *s.begin();
        // printf("%s\n", temp.c_str());
        for (int i = 1; i < size; i++) {
            if (temp[i-1] == '0') {
                if (temp[i] > '0') {
                    t = temp;
                    t[i-1] = '2';
                    t[i] = temp[i] - 1;
                    if (s.count(t) == 0) s.insert(t), ans++;
                }
            }
        }
        s.erase(temp);
    }
    printf("%d\n", ans);
    return 0;
}

// int calc(int n) {
//         if (n == 0) return 1;
//         if (n % 2 == 0) return calc(n / 2) + calc(n / 2 - 1);
//         return calc(n / 2);
// }

// int main() {
//         int n;
//         cin >> n;
//         cout << calc(n) << endl;
//         return 0;
// }