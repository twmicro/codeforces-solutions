#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    int tt;
    cin >> tt;
    while(tt--) {
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        int l, r, d, u;
        l = r = d = u = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'U') u++;
            else if(s[i] == 'D') d++;
            else if(s[i] == 'L') l++;
            else r++;
        }
        bool enough = true;
        if(x > 0) enough &= (r >= x);
        if(x < 0) enough &= ((0 - l) <= x);
        if(y > 0) enough &= (u >= y);
        if(y < 0) enough &= ((0 - d) <= y);
        cout << (enough ? "YES" : "NO") << endl;
    }
    return 0;
}

