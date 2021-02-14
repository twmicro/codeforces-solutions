#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int cnt[10];
int main() {
    int tt;
    cin >> tt; 
    while(tt--) {
        memset(cnt, 0, sizeof(cnt));
        string s;
        cin >> s;
        n = (int)s.size();
        int mx1 = 0, mx2 = 0;
        for(int i = 0; i < n; i++) cnt[s[i] - '0']++, mx1 = max(mx1, cnt[s[i] - '0']);
        for(int i = 0; i < 10; i++) {
            for(int j = i + 1; j < 10; j++) {
                int norm = 0, rev = 0, exp1 = i, exp2 = j;
                for(int x = 0; x < n; x++) {
                    int c = s[x] - '0';
                    if(exp1 == c) {
                        norm++;
                        exp1 = (exp1 == i ? j : i);
                    }
                    if(exp2 == c) {
                        rev++;
                        exp2 = (exp2 == j ? i : j);
                    }
                }
                mx2 = max(mx2, max(norm - (norm & 1), rev - (rev & 1)));
            }
        }
        cout << n - max(mx1, mx2) << "\n";
    }
    return 0;
}
