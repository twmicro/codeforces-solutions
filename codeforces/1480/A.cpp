#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        string s;
        cin >> s;
        int turn = 0;
        for(int i = 0; i < s.size(); i++) {
            if(!turn) {
                if(s[i] == 'a') s[i] = 'b';
                else s[i] = 'a';
            } else {
                if(s[i] == 'z') s[i] = 'y';
                else s[i] = 'z';
            }
            turn = !turn;
        }
        cout << s << endl;
    }
}
