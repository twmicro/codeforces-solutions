#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

struct segtree {
    struct node {
        int value;
        int index;
    };
    vector<node> tree;
    int size;
    

    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree = vector<node>(2 * size - 1);
        for(int i = 0; i < 2 * size - 1; i++) tree[i].value = 0, tree[i].index = i;
    } 
 
    void build(vector<int> a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int)a.size()) {
                tree[x].value = a[lx];
                tree[x].index = lx;
            }
        } else {
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            if(tree[2 * x + 1].value > tree[2 * x + 2].value) {
                tree[x].value = tree[2 * x + 1].value;
                tree[x].index = tree[2 * x + 1].index;
            } else {
                tree[x].value = tree[2 * x + 2].value;
                tree[x].index = tree[2 * x + 2].index;
            }
        }
    }
 
    void build(vector<int> a) {
        init(a.size());
        build(a, 0, 0, size);
    }
 
    node max(int l, int r, int x, int lx, int rx) {
        if(lx >= r || rx <= l) return node{0, 0};
        else if(lx >= l && rx <= r) return node{tree[x].value, tree[x].index};
        else {
            int m = (lx + rx) / 2;
            node lmx = max(l, r, 2 * x + 1, lx, m);
            node rmx = max(l, r, 2 * x + 2, m, rx);
            if(lmx.value > rmx.value) {
                return lmx;
            } else {
                return rmx;
            }
        }
    }
 
    node max(int l, int r) {
        return max(l, r, 0, 0, size);
    }
};

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> depths(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        segtree st;
        st.build(a);
        queue<pair<int, int>> q; q.push({0, n});
        int depth = 0;
        while(!q.empty()) {
            int sz = (int)q.size();
            for(int i = 0; i < sz; i++) {
                auto [l, r] = q.front();
                q.pop();
                auto mx = st.max(l, r);
                depths[mx.index] = depth;
                if(mx.index > l) q.push({l, mx.index});
                if(mx.index < r - 1) q.push({mx.index + 1, r});
            }
            depth++;
        }
        for(int i = 0; i < n; i++) cout << depths[i] << " ";
        cout << endl;
    }
    return 0;
}

