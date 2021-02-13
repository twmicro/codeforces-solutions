#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        long long n, x;
        cin >> n >> x;
        vector<pair<long long, long long>> a(n);

        for(int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            a.push_back({x, 1});
        }

        for(int i = 0; i < (int)a.size(); i++) {
            auto [q, times] = a[i];
            if(q % x == 0) a.push_back({q / x, times * x});
            else break;
        }

        long long sm = 0;
        for(int i = 0; i < (int)a.size(); i++) sm += a[i].first * a[i].second;
        cout << sm << "\n";
    }
    return 0;
}
