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
        for(int i = 0; i < n; i++) cin >> a[i];
        if(k > 10000) {
            cout << -1 << endl;
            continue;
        }
        int pos = -1;
        for(int t = 0; t < k; t++) {
            bool exit = false;
            for(int i = 0; i < n-1; i++) {
                if(a[i] < a[i+1]) {
                    exit = true;
                    a[i]++;
                    pos = i + 1;
                    break;
                }
            }
            if(!exit) pos = -1;
        }
        cout << pos << endl;
    }
    return 0;
}

