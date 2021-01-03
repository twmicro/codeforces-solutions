#include <bits/stdc++.h>
using namespace std;
class dsu {
    public:
        int n;
        vector<int> p;

        dsu(int _n) {
            n = _n;
            p.resize(n);
            iota(p.begin(), p.end(), 0);
        }

        int get(int v) {
            if(v == p[v]) return v;
            else {
                p[v] = get(p[v]);
                return p[v];
            }
        }

        bool unite(int x, int y) {
            x = get(x);
            y = get(y);
            if(x != y) {
                p[x] = y;
                return true;
            }
            return false;
        }
};

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m, s = 0, cyc = 0; cin >> n >> m;
        dsu d(n);
        for(int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            if(x == y) ++s;
            else if(!d.unite(x-1, y-1)) cyc++;
        }
        cout << m - s + cyc << endl;
    }
    return 0;
}