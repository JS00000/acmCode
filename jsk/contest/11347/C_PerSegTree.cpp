#include <bits/stdc++.h>
using namespace std;
 
class PerSegTree {
  private:
    struct Node {
        int sum, left, right;
        Node(int sum = 0, int left = -1, int right = -1) :
            sum(sum), left(left), right(right) { }
    };
 
    int n;
    vector<Node> tree;
    vector<int> roots;
 
    void build(int node, int left, int right) {
        if (left == right)
            return;
        tree[node].left = tree.size();
        tree.emplace_back();
        tree[node].right = tree.size();
        tree.emplace_back();
        int mid = (left + right) / 2;
        build(tree[node].left, left, mid);
        build(tree[node].right, mid + 1, right);
    }
 
    int update(int node, int left, int right, int pos) {
        if (left == right) {
            tree.emplace_back(tree[node].sum + 1);
            return tree.size() - 1;
        }
        int mid = (left + right) / 2;
        int crtLeft = tree[node].left, crtRight = tree[node].right;
        if (pos <= mid)
            crtLeft = update(tree[node].left, left, mid, pos);
        else
            crtRight = update(tree[node].right, mid + 1, right, pos);
        tree.emplace_back(tree[crtLeft].sum + tree[crtRight].sum, crtLeft, crtRight);
        return tree.size() - 1;
    }
 
    int query(int left, int right, int x, int y, int frq) {
        if (tree[y].sum - tree[x].sum < frq)
            return -1;
        if (left == right)
            return left;
        int mid = (left + right) / 2;
        if (tree[tree[y].left].sum - tree[tree[x].left].sum >= frq) {
            int ansLeft = query(left, mid, tree[x].left, tree[y].left, frq);
            if (ansLeft != -1)
                return ansLeft;
        }
        if (tree[tree[y].right].sum - tree[tree[x].right].sum >= frq) {
            int ansRight = query(mid + 1, right, tree[x].right, tree[y].right, frq);
            if (ansRight != -1)
                return ansRight;
        }
        return -1;
    }
 
  public:
    PerSegTree(int n) :
        n(n), tree(1), roots(n + 1) {
            build(0, 1, n);
        }
 
    void add(int val) {
        static int pos = 0; pos++;
        roots[pos] = update(roots[pos - 1], 1, n, val);
    }
 
    int query(int left, int right, int frq) {
        return query(1, n, roots[left - 1], roots[right], frq);
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, q; cin >> n >> q;
    PerSegTree pst(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pst.add(x);
    }
    for (int i = 0; i < q; i++) {
        int l, r, k; cin >> l >> r >> k;
        cout << pst.query(l, r, (r - l + 1) / k + 1) << '\n';
    }
    return 0;
}