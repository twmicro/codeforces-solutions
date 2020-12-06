#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        while(s.find("t", 0) != string::npos && s.find("r", s.find("t", 0)) != string::npos && s.find("y", s.find("r", 0)) != string::npos && s.find("g", s.find("y", 0)) != string::npos && s.find("u", s.find("g", 0)) != string::npos && s.find("b", s.find("u", 0)) != string::npos) {
            size_t occur = s.find("t", 0);
            size_t occur1 = s.find("r", s.find("t", 0));
            char tmp = s[occur1];
            s[occur1] = s[occur];
            s[occur] = tmp;
        }
        cout << s << endl;
    }

    return 0;
}