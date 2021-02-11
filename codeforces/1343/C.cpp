#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        long long sum = 0;
        int mx = -1e9;
        for(int i = 0; i < n + 1; i++) {
            if(i && (i == n || ((a[i] > 0) != (a[i-1] > 0)))) {
                sum += mx;
                mx = -1e9;
            }
            if(i < n) mx = max(mx, a[i]);
        }
        cout << sum << "\n";
    }
    return 0;
}
