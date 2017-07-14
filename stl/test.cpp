#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

typedef long long LL;
using namespace std;
const int maxn = 201;
const double PI = acos(-1.0);


void f()
{
    int aaaa[maxn][maxn];
    aaaa[maxn-1][maxn-1] = 1;
    return;
}


bool mycmp(int a, int b)
{
    return a > b;
}

int main(int argc, char const *argv[])
{
    std::map<string, int> mp;
    mp["aaa"] = 1;
    printf("%d\n", mp["asdfs"]);
    if (!mp.count("asdfs")) printf("sdafds\n");
    else printf("yes\n");
    mp.erase("asdfs");

    mp.clear();

    set<string> st;
    st.insert("asdfsadf");
    st.insert("bbb");

    st.erase("asdfsadf");

    cout << st.size() << endl;

    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);

    f();



    priority_queue<int> q;
    q.push(1);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(2);
    q.push(0);

    printf("%d\n", q.top());


    int a[maxn];
    for (int i = 0; i < 10; ++i)
        a[i] = 10-i;
    for (int i = 0; i < 10; ++i)
        printf("%d ", a[i]);
    printf("\n");

    sort(a, a+10, mycmp);

    for (int i = 0; i < 10; ++i)
        printf("%d ", a[i]);
    printf("\n");
    

    return 0;
}

