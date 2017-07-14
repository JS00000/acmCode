// Trie图
#include <queue>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

struct trie_node;
vector<trie_node*> nodes;
struct trie_node
{
    trie_node *child[26], *next;
    int cnt;
    trie_node()
    {
        memset(child, 0, sizeof(child));
        next = NULL;
        cnt = 0;
        nodes.push_back(this);
    }
}*root;

void insert(string s)
{
    trie_node* p=root;
    for (std::string::iterator it = s.begin(); it != s.end(); ++it)
    {
        if(p->child[*it-'a'] == NULL) p->child[*it-'a'] = new trie_node();
        p=p->child[*it-'a'];
    }
    p->cnt++;
}

void bfs()
{
    queue<trie_node*> myqueue;
    myqueue.push(root);
    while(!myqueue.empty())
    {
        trie_node *p=myqueue.front(), *temp;
        myqueue.pop();
        for(int i=0; i<26; i++)
        {
            if(p->child[i])
            {
                if(p==root) p->child[i]->next = root;
                else
                {
                    temp = p->next;
                    while(temp->child[i] == NULL && (temp != root)) temp = temp->next;
                    p->child[i]->next = temp->child[i];
                    if(p->child[i]->next == NULL) p->child[i]->next = root;
                }
                myqueue.push(p->child[i]);
            }
        }
    }
}
int solve(string s)
{
    trie_node *p=root;
    for (std::string::iterator it = s.begin(); it != s.end(); ++it)
    {
        int t = *it-'a';
        while(p->child[t] == NULL && p != root) p = p->next;
        p = p->child[t];
        if(p == NULL) p = root;
        trie_node *temp = p;
        if (temp->cnt > 0) return 1;
        // while(temp != root && temp->cnt != -1)
        // {
        //     // if (temp->cnt > 0) return 1;
        //     temp->cnt = -1;
        //     temp = temp->next;
        // }
    }
    return 0;
}
int main()
{
    std::cin.sync_with_stdio(false);
    string s;
    root = new trie_node();
    root->next = root;
    int n;
    cin >> n;
    while(n--)
    {
        cin >> s;
        insert(s);
    }
    bfs();
    cin >> s;
    cout << (solve(s) ? "YES": "NO") << endl;
    return 0;
}
