#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ceildiv(int a, int b) {
    if(a % b) return a / b + 1;
    else return a / b;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        if((ceildiv(a, c) + ceildiv(b, d)) > k) cout << -1 << "\n";
        else cout << ceildiv(a, c) << " " << ceildiv(b, d) << "\n";
    }
    return 0;
}
