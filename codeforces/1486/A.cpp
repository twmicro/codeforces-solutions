#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        long long sm = 0;
        bool ok = true;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n && ok; i++) {
            if(a[i] < i && ((long long)a[i] + sm) < i) {
                ok = false;
                break;
            }
            sm += a[i] - i;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}

