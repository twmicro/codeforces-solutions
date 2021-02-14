#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    bool bf[10][110];
    memset(bf, 0, sizeof(bf));
    for(int i = 1; i < 10; i++) {
        bf[i][0]=1;
        for(int j = 0; 10 * j + i <= i * 10; j++) {
            for(int k = 0; 10 * j + i + k <= i * 10; k++) {
                bf[i][10*j+i+k]|=bf[i][k];
            }
        }
    }
    int tt;
    cin >> tt;
    while(tt--) {
        int q, d;
        cin >> q >> d;
        while(q--) {
            int x;
            cin >> x;
            if(x >= d * 10) cout << "YES" << "\n";
            else cout << (bf[d][x] ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
