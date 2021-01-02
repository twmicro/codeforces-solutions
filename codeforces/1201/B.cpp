#include <bits/stdc++.h>
using namespace std;

int main() {
    long long sum = 0;
    long long mx = 0;
    int n; cin >> n;
    while(n--) {
        long long el; cin >> el;
        sum += el;
        mx = max(mx, el);
    }
    cout << (sum % 2 == 0 && mx <= sum - mx ? "YES" : "NO") << endl;
    return 0;
}