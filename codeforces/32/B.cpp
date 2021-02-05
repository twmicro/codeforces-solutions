#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    char last = '$';
    string result = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '-') {
            if(s[i + 1] == '.') {
                result += "1";
                i++;
            } else {
                result += "2";
                i++;
            }
        } else result += "0";
    }
    cout << result << endl;
    return 0;
}
