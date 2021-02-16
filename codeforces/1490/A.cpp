#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll ans = 0;
        for(int i = 0; i < n - 1; i++) {
            int mn = min(a[i], a[i+1]);
            int mx = max(a[i], a[i+1]);
            if(mn * 2 < mx) {
                while(mn * 2 < mx) mn *= 2, ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

