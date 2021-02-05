#include <bits/stdc++.h>
using namespace std;

string to_lower_case(string s) {
    for(int i = 0; i < s.size(); i++) {
        if(int(s[i]) < 97) {
            s[i] = char(int(s[i]) + 32);
        }
    }
    return s;
}

string to_upper_case(string s) {
    for(int i = 0; i < s.size(); i++) {
        if(int(s[i]) >= 97) {
            s[i] = char(int(s[i]) - 32);
        }
    }
    return s;
}

bool case_of(char ch) {
    if(int(ch) >= 97) return 0;
    else return 1;
}

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int cs = 0;
    for(int i = 0; i < s.size(); i++) {
        if(case_of(s[i])) cs++;
        else cs--;
    }
    if(cs > 0) cout << to_upper_case(s) << endl;
    else cout << to_lower_case(s) << endl;
    return 0;
}
