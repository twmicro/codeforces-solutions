#include <bits/stdc++.h>
#define VISITED 1
#define UNVISITED 0
using namespace std;
class dsu {
    public:
        vector<int> p;
        int n;
        int ccc;
        dsu(int _n) : n(_n) {
            p.resize(n);
            ccc = n;
            iota(p.begin(), p.end(), 0);
        }
        
        inline int get(int x) {
            return (x == p[x] ? x : (p[x] = get(p[x])));
        }
        
        inline bool unite(int x, int y) {
            x = get(x);
            y = get(y);
            if (x != y) {
                p[x] = y;
                ccc--;
                return true;
            }
            return false;
        }

        void cc(vector<pair<int, int>> cyc) {
            int ind = 0;
            for(int i = 0; i < p.size(); i++) {
                if(get(i) != get(0)) {
                    cout << cyc[ind].first + 1 << " " << cyc[ind].second + 1 << " " << 1 << " " << i + 1 << endl;
                    unite(0, i);
                    ind++;
                }
            }
        }
};


int main() {
    int t; cin >> t;
    dsu d(t);
    t--;
    int ans = 0;
    vector<pair<int, int>> cyc;
    while(t--) {
        int u, v; cin >> u >> v;
        u--; v--;
        if(!d.unite(u, v)) cyc.push_back(make_pair(u, v));
    }
    cout << d.ccc - 1 << endl;
    d.cc(cyc);
    return 0;
}