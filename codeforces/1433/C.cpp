#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int mxvl = 0;
        int res = -1;
        vector<int> v;
        for(int i = 0; i < n; i++) {
            int el; cin >> el;
            if(mxvl < el) mxvl = el;
            v.push_back(el);
        }
        for(int i = 0; i < n; i++) {
            if(v[i] != mxvl) continue;
            if((i > 0 && v[i - 1] != mxvl) || (i < n - 1 && v[i + 1] != mxvl)) res = i + 1;
        }
        cout << res << endl;
    }
    return 0;
}