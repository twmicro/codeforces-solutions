#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1 + 1 == l2 + 1) cout << l1 << " " << r2 << "\n";
        else cout << l1 + 1 << " " << l2 + 1 << "\n";
    }   
    return 0;
}
