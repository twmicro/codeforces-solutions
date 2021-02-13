#include <bits/stdc++.h>
using namespace std;

long long ceil_div(long long a, long long b) {
    if(a % b) return a / b + 1;
    else return a / b;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        long long mn = 0, mx = 0;
        for(int i = 0; i < n; i++) {
            mx += ceil_div(a[i], x);
            mn += a[i];
        }
        mn = ceil_div(mn, x);
        cout << mn << " " << mx << "\n";
    }
    return 0;
}
