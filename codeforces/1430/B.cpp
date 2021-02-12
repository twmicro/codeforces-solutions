#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        for(int i = n - 2; i >= max(n - k - 1, 0); i--) a[n-1] += a[i];
        cout << a[n-1] << "\n";
    }
    return 0;
}
