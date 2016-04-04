#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define mp make_pair
#define pii pair<int, int>
using namespace std;

int a[5], req[5];

int main (void) {
    ios::sync_with_stdio(false);
    for (int i=0; i<3; i++)
        cin >> a[i];
    for (int i=0; i<3; i++)
        cin >> req[i];
    for (int i=0; i<3; i++) {
        if (a[i] <= req[i])
           continue;
        int v = (a[i] - req[i]) / 2;
        for (int j=0; j<3; j++)
            if (a[j] < req[j]) {
               int g = min(v, req[j] - a[j]);
               v -= g;
               a[j] += g;
            }
    }
    for (int i=0; i<3; i++)
        if (a[i] < req[i]) {
           cout << "No" << endl;
           return 0;
        }
    cout << "Yes" << endl;
    return 0;
}