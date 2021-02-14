#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n < 3) {
        if(n == 1) {
            cout << 0 << "\n";
            cout << s << "\n";
        } else {
            cout << (s[0] == s[1] ? 1 : 0) << "\n";
            if(s[0] == 'R') {
                if(s[1] == 'R') cout << "RG" << "\n";
                else cout << s << "\n";
            } else if(s[0] == 'G') {
                if(s[1] == 'G') cout << "GB" << "\n";
                else cout << s << "\n";
            } else {
                if(s[1] == 'B') cout << "BR" << "\n";
                else cout << s << "\n";
            }
        }
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < n - 2; i++) {
        if(s[i] == s[i + 1]) {
            ans++;
            if(s[i] == 'R') {
                if(s[i + 2] == 'B' || s[i + 2] == 'R') s[i + 1] = 'G';
                else s[i + 1] = 'B';
            } else if(s[i] == 'G') {
                if(s[i + 2] == 'B' || s[i + 2] == 'G') s[i + 1] = 'R';
                else s[i + 1] = 'B';
            } else {
                if(s[i + 2] == 'B' || s[i + 2] == 'G') s[i + 1] = 'R';
                else s[i + 1] = 'G';
            }
        }
    }
    if(s[n-1] == s[n-2]) {
        ans++;
        if(s[n-1] == 'R') s[n-1] = 'B';
        else s[n-1] = 'R';
    }
    cout << ans << "\n";
    cout << s << "\n";
    return 0;
}
