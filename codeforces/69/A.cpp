#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    long long sm = 0;
    int mat[100][3];
    int sm1 = 0, sm2 = 0, sm3 = 0;
    for(int i = 0; i < n; i++) cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    for(int i = 0; i < n; i++) {
        sm1 += mat[i][0];
        sm2 += mat[i][1];
        sm3 += mat[i][2];
    }
    cout << (sm1 == 0 && sm2 == 0 && sm3 == 0 ? "YES" : "NO") << endl;
    return 0;
}
