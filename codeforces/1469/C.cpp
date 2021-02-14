#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int tt;
    cin >> tt; 
    while(tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> h(n);
        for(int i = 0; i < n; i++) cin >> h[i];
        int mn = h[0], mx = h[0];
        bool ok = 1;
        for(int i = 1; i < n; i++) {
            mn = max(mn - k + 1, h[i]);
            mx = min(mx + k - 1, h[i] + k - 1);
            ok &= (mn <= mx);
        }
        ok &= (h[n-1] >= mn && h[n-1] <= mx);
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
