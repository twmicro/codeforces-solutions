#include <bits/stdc++.h>
using namespace std;

int ceilint(int a, int b) {
    if(a % b) return a / b + 1;
    else return a / b;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int a, b, n;
        cin >> a >> b >> n;
        vector<pair<int, int>> monsters(n);
        vector<int> damages(n);
        for(int i = 0; i < n; i++) cin >> damages[i];
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            //cout << "reading... x=" << x << endl;
            monsters[i] = {damages[i], x};
        }
        //cout << "no bugs!" << endl;
        sort(monsters.begin(), monsters.end());
        bool ans = true;
        for(int i = 0; i < n; i++) {
            if(b < 1) {
                ans = false;
                break;
            }
            //cout << "monster[i].second=" << monsters[i].second << "; a=" << a << "; b="  << b << "; monsters[i].first=" << monsters[i].first << endl;
            if(ceilint(monsters[i].second, a) > ceilint(b, monsters[i].first)) {
                ans = false;
                break;
            }
            b -= monsters[i].first * (ceilint(monsters[i].second, a));
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
}
