#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    string res = "/";
    string buff = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '/') {
            if(buff != "")
                res += buff + '/';
            buff = "";
        }
        else
            buff += s[i];
    }
    if(buff == "" && res[res.size()-1] == '/' && res.size() > 1) cout << res.substr(0, res.size()-1) << endl;
    else cout << res + buff << endl;
    return 0;
}

