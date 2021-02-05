#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int sum = 0;
        int mn = INT_MAX;
        int ind = -1;
        int res = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            if(a[i] < mn) {
                ind = i;
                mn = a[i];
            }
        }
        for(int i = 0; i < n; i++) {
            if(i != ind) {
                res += (k - a[i]) / mn;
            }
        }
        cout << res << endl;
    }
    return 0;
}

