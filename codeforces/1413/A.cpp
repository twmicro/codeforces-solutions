#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = 0; i < n / 2; i++) { 
            int a, b; cin >> a >> b;
            cout << -b << " " << a << (i == n - 1 ? "\n" : " ");
        }
    }
    return 0;
}
