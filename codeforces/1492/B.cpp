#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct segtree {
    vector<int> tree;
    vector<int> pos;
    int size;
 
    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.assign(2 * size - 1, 0);
        pos.assign(2 * size - 1, -1);
    }
    
    void build(vector<int> &a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int)a.size()) {
                tree[x] = a[lx];
                pos[x] = lx;
            }
        } else {
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            if(tree[2 * x + 1] > tree[2 * x + 2]) {
                pos[x] = pos[2 * x + 1];
                tree[x] = tree[2 * x + 1];
            } else {
                pos[x] = pos[2 * x + 2];
                tree[x] = tree[2 * x + 2];
            }
        }
    }

    void build(vector<int> &a) {
        init((int)a.size());
        build(a, 0, 0, size);
    }

    pair<int, int> max(int l, int r, int x, int lx, int rx) {
        if(lx >= r || rx <= l) return {-1, 0};
        else if(lx >= l && rx <= r) return {pos[x], tree[x]};
        else {
            int m = (lx + rx) / 2;
            auto [lp, lv] = max(l, r, 2 * x + 1, lx, m);
            auto [rp, rv] = max(l, r, 2 * x + 2, m, rx);
            return {(lv > rv ? lp : rp), ::max(lv, rv)};
        }
    }

    int max_pos(int l, int r) {
        return max(l, r, 0, 0, size).first;
    }
};

int main() {
    // Please, AC!
    int tt;
    cin >> tt;
    segtree st;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> res(n), a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        st.build(a);
        int r = n;
        while(r > 0) {
            int mp = st.max_pos(0, r);
            for(int i = mp; i < r; i++) cout << a[i] << " ";
            r = mp;
        }
        cout << endl;
    }
    return 0;
}
