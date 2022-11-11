class segTree {
  public:
    int size;
    vll tree;

    segTree(int n) {
        size = 1;
        while (size <= n)
            size *= 2LL;
        tree.resize(2 * size);
    }

    ll f(ll a, ll b) { return a + b; }

    void update(int idx, int val, int node, int l, int r) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int m = (l + r) / 2;

        if (idx <= m) {
            update(idx, val, 2 * node, l, m);
        } else {
            update(idx, val, 2 * node + 1, m + 1, r);
        }

        tree[node] = f(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int idx, int val) { update(idx, val, 1, 0, size - 1); }

    ll query(ll ql, ll qr, int node, int nl, int nr) {

        if (ql > nr || qr < nl) {
            return 0;
        }

        if (nl == nr) {
            return tree[node];
        }

        if (ql <= nl && nr <= qr) {
            return tree[node];
        }

        int m = (nl + nr) / 2;

        return f(query(ql, qr, 2 * node, nl, m), query(ql, qr, 2 * node + 1, m + 1, nr));
    }

    ll query(int ql, int qr) { return query(ql, qr, 1, 0, size - 1); }
};
