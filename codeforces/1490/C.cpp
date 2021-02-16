#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

ll bruteforces[10001];

bool find(ll x) {
    int l = 0, r = 10000;
    while(r >= l) {
        int m = (l + r) / 2;
        if(x == bruteforces[m]) return true;
        if(x < bruteforces[m]) r = m - 1;
        else l = m + 1;
    }
    return false;
}

int main() {
    int tt;
    for(ll i = 0; i <= 10000; i++) bruteforces[i] = i * i * i;
    cin >> tt;
    while(tt--) {
        ll x;
        cin >> x;
        bool found = false;
        for(int i = 1; i <= 10000; i++) {
            ll tmp = x - bruteforces[i];
            if(tmp < 1) break;
            if(find(tmp)) {
                found = true;
                break;
            }
        }
        cout << (found ? "YES" : "NO") << "\n";
    }
    return 0;
}

