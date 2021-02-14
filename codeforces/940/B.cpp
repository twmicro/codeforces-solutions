#include <bits/stdc++.h>
using namespace std;

long long nearest_div(long long n, long long k) {
    return n - n % k;
}

long long solve(long long n, long long k, long long a, long long b) {
    if(n == 1) return 0;
    int nd = nearest_div(n, k);
    if(nd == 0) return (n - 1) * a;
    if(nd != n) return (n - nd) * a + solve(nd, k, a, b);
    return min((n - n / k) * a, b) + solve(n / k, k, a, b);
}

int main() {
    long long n, k, a, b;
    cin >> n >> k >> a >> b;
    if(k == 1) cout << (n - 1) * a << "\n";
    else cout << solve(n, k, a, b) << "\n";
    return 0;
}
