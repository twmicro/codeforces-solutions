#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    long long n, q, k;
    cin >> n >> q >> k;
    vector<long long> a(n), precalc(n), prefix_sums(n);
    for(int i = 0; i < n; i++) { 
        scanf("%lld", &(a[i]));
        if(i == 0) precalc[i] = a[i] - 1;
        else if(i == n - 1) precalc[i] = k - a[i] + (n > 1 ? a[i] - a[i - 1] - 1 : 0);
        else precalc[i] = a[i] - a[i - 1] - 1;
        if(i != 0 && n > 1) precalc[i - 1] += a[i] - a[i - 1] - 1;
    }

    for(int i = 0; i < n; i++) { 
        prefix_sums[i] = (i > 0 ? prefix_sums[i - 1] : 0) + precalc[i];
        //cout << "Precalc[" << i << "] = " << precalc[i] << "\n";
        //cout << "Prefix_Sum[" << i << "] = " << prefix_sums[i] << "\n";
    }
    while(q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--; r--;
        long long first = a[l] - 1 + (r - l ? a[l + 1] - a[l] - 1 : 0);
        long long last = k - a[r] + (r - l ? a[r] - a[r - 1] - 1 : 0);
        long long sm = first + last + (r - l ? prefix_sums[r - 1] - prefix_sums[l] : 0);
        printf("%lld\n", sm);
    }
    return 0;
}
