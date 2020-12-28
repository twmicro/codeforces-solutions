#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, s1; cin >> s >> s1;
    for(int i = 0; i < s.length(); i++) {
        char sc = tolower(s[i]);
        char s1c = tolower(s1[i]);
        if(sc == s1c) continue;
        else {
            cout << (sc < s1c ? -1 : 1) << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}