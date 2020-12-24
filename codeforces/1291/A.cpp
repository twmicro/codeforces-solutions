#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#define pb push_back
#define str to_string
#define len length
#define mxel max_element
#define mnel min_element
#define sum accumulate
#define FORI(n, step) for(int i = 0; i < n; i += step)
#define FORJ(n, step) for(int j = 0; j < n; j += step)
#define FORX(n, step) for(int x = 0; x < n; x += step)
#define FORY(n, step) for(int y = 0; y < n; y += step)
#define FORU(n, step) for(int u = 0; u < n; u += step)
#define FORV(n, step) for(int v = 0; v < n; v += step)
#define EACHI(n) FORI(n, 1)
#define EACHJ(n) FORJ(n, 1)
#define EACHX(n) FORX(n, 1)
#define EACHY(n) FORY(n, 1)
#define EACHZ(n) FORZ(n, 1)
#define EACHU(n) FORU(n, 1)
#define EACHV(n) FORV(n, 1)
using namespace std;
using vi = vector<int>;
using graph = vector<vi>;
using ll = long long;


void oc(vi v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
        if(i != v.size() - 1) cout << " ";
        else cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        string res = "";
        for(int i = 0; i < n; i++) {
            if(stoi(string(1, s[i])) % 2 != 0) res += s[i];
        }
        cout << (res.length() > 1 ? res.substr(0, 2): "-1") << endl;
    }
    return 0;
}