#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int mn = 1e9, ans = 0;
        for(int i = 0; i < n; i++) { 
            cin >> a[i];
            mn = min(mn, a[i]);
        }
        for(int i = 0; i < n; i++)
            if(a[i] > mn)
                ans++;
        cout << ans << "\n";  
    }
    return 0;
}

