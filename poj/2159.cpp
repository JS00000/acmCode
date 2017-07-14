#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char c;
	int a[26], b[26], n = 0;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	while(c = getchar(), c != '\n') a[c-'A']++;
	sort(a, a+26);
	while(c = getchar(), c != '\n') b[c-'A']++;
	sort(b, b+26);
	bool p = true;
	for (int i = 0; i < 26; i++) if (b[i] != a[i]) p = false;
 	if (p) printf("YES\n"); else printf("NO\n");
	return 0;
}
