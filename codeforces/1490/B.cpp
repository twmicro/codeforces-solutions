#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        int c[3];
        c[0] = c[1] = c[2] = -(n / 3);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            c[x % 3]++;
        }
        int ans = 0;
        while(c[0] != c[1] || c[1] != c[2]) {       
            if(c[2] > 0) c[0] += c[2], ans += c[2], c[2] = 0;
            if(c[0] > 0) c[1] += c[0], ans += c[0], c[0] = 0;
            if(c[1] > 0) c[2] += c[1], ans += c[1], c[1] = 0; 
        }
        cout << ans << endl;
    }
    return 0;
}

