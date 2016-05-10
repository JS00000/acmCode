#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>


typedef long long LL;

const LL MAX_INT = 0x7fffffffffffffff;
const LL MIN_INT = 0x8000000000000000;

using namespace std;

struct HuffmanNode
{
	unsigned int w,p,l,r;
	char c;
};

vector<HuffmanNode> HuffmanTree;
map<char, string> HuffmanCode;

void huffmanCoding(vector<HuffmanNode> &H, map<char, string> &HC, map<char, int> &w)
{
	if (w.size() < 1) return;
	H.clear();
	H.resize(w.size()*2);
	int k = 1;
	for (std::map<char, int>::iterator it = w.begin(); it != w.end(); ++it, ++k)
	{
		H[k].c = it->first;
		H[k].w = it->second;
	}
	for (int i = w.size() + 1; i < H.size(); ++i)
	{
		LL min1 = MAX_INT, min2 = MAX_INT;
		int s1 = 0, s2 = 0;
		for (int j = 1; j < i; ++j)
		{
			if (H[j].p == 0)
			{
				if (min1 > H[j].w)
				{
					if (!s1)
					{
						s2 = s1;
						min2 = min1;
					}
					min1 = H[j].w;
					s1 = j;
				}
				else if (min2 > H[j].w)
				{
					min2 = H[j].w;
					s2 = j;
				}
			}
		}
		H[s1].p = i;
		H[s2].p = i;
		H[i].l = s1;
		H[i].r = s2;
		H[i].w = H[s1].w + H[s2].w;
	}

	HC.clear();
	char code[w.size()];
	code[w.size() - 1] = '\0';
	k = 1;
	for (std::map<char, int>::iterator it = w.begin(); it != w.end(); ++it, ++k)
	{
		int pos = w.size() - 1;
		int son = k;
		int p = H[k].p;
		while(p != 0)
		{
			if (H[p].l == son) code[--pos] = '0';
			else code[--pos] = '1';
			son = p;
			p = H[p].p;
		}
		HC[it->first] = string(&code[pos]);
	}
}

string HuffmanDecode(string &sc)
{
	string ret;
	int p = HuffmanTree.size() - 1;
	for (std::string::iterator it = sc.begin(); it != sc.end();)
	{
		if (*it == '0')
		{
			p = HuffmanTree[p].l;
			it++;
		}
		else
		{
			p = HuffmanTree[p].r;
			it++;
		}
		if (p > 0 && p <= HuffmanCode.size())
		{
			ret += HuffmanTree[p].c;
			p = HuffmanTree.size() - 1;
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	map<char, int> para;
	fstream fin("text.in");
	char c;
	while(fin.get(c))
		para[c]++;
	fin.close();

	huffmanCoding(HuffmanTree, HuffmanCode, para);

	// for (std::vector<HuffmanNode>::iterator i = HuffmanTree.begin(); i != HuffmanTree.end(); ++i)
		// cout << i->c << " " << i->p << " " << i->w << " " << i->l << " " << i->r << endl;
	// cout << endl;

	// for (std::map<char, string>::iterator it = HuffmanCode.begin(); it != HuffmanCode.end(); ++it)
		// cout << "'" << it->first << "'" << " :" << it->second << endl;


	string sc;
	cout << "\nThe HuffmanCode of the text is:\n";
	fin.open("text.in");
	while(fin.get(c)) sc += HuffmanCode[c];
	fin.close();
	cout << sc << endl;


	cout << "\nThe Origin text is:\n";
	string ans = HuffmanDecode(sc);
	cout << ans << endl;



	return 0;
}
