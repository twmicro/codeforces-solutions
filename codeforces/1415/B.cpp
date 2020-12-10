
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;
using vi = vector<int>;

int cache = -1;
bool all_equal(vi v, int i) {
    if (v.size() < 2) return true;
    vi::iterator iter = find_if(v.begin(), v.end(), [&i](int x){return x != i;});                 
    if (iter == v.end()) return true;
    else {
        cache = distance(v.begin(), iter);
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) { 
        int n, k; cin >> n >> k;
        vi v;
        int best = INT32_MAX;
        for (int i = 0; i < n; i++) { 
            int vin; cin >> vin;
            v.pb(vin);
        }

        for (int i = 0; i < 101; i++) {
            int count = 0;
            for (int j = 0; j < v.size(); j++) {
                if(v[j] != i) { 
                    j += k - 1;
                    count++;
                }
            }
            if(count < best) best = count;
        }

        cout << best << endl;
    }
    return 0;
}
