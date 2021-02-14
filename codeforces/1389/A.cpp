#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int cnt[10];
int main() {
    int tt;
    cin >> tt; 
    while(tt--) {
        int l, r;
        cin >> l >> r;
        if(2 * l > r) cout << -1 << " " << -1 << "\n";
        else cout << l << " " << 2 * l << "\n";
    }
    return 0;
}
