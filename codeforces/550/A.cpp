#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> ab, ba;
    for(int i = 0; i < (int)s.size() - 1; i++) {
        if(s[i] == 'A' && s[i + 1] == 'B') ab.push_back(i);
        else if(s[i] == 'B' && s[i + 1] == 'A') ba.push_back(i);
    }
    if(int(ab.size()) == 0 || int(ba.size()) == 0) cout << "NO" << endl;
    else if(abs(ab[0] - ba[(int)ba.size() - 1]) > 1 || abs(ab[(int)ab.size() - 1] - ba[0]) > 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
