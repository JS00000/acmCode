// Trie树
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const int CHARSET = 26, BASE = 'a', MAX_NODE = 70007;
struct Trie
{
	int tot, root, child[MAX_NODE][CHARSET];
	bool flag[MAX_NODE];
	Trie()
	{
		memset(child[1], 0, sizeof(child[1]));
		flag[1] = false;
		root = tot = 1;
	}
	void insert(const char *str)
	{
		int *cur = &root;
		for (const char *p = str; *p; ++p)
		{
			cur = &child[*cur][*p-BASE];
			if (*cur == 0)
			{
				*cur = ++tot;
				memset(child[tot], 0, sizeof(child[tot]));
				flag[tot] = false;
			}
		}
		flag[*cur] = true;
	}
	bool query(const char *str)
	{
		int *cur = &root;
		for (const char *p = str; *p && *cur; ++p)
			cur = &child[*cur][*p - BASE];
		return (*cur && flag[*cur]);
	}
};

int main(int argc, char const *argv[])
{
	Trie tree;
	char s[5] = "good";
	tree.insert(s);
	cout << tree.query("good") << endl;
	return 0;
}