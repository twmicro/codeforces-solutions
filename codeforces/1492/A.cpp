#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    // Please, AC!
    int tt;
    cin >> tt;
    while(tt--) {
        long long p, a, b, c;
        cin >> p >> a >> b >> c;
        ll first = p % a;
        ll second = p % b;
        ll third = p % c;
        if(first == 0 || second == 0 || third == 0) cout << 0 << endl;
        else cout << min(a - first, min(b - second, c - third)) << endl;
    }
    return 0;
}
