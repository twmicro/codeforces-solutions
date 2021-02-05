#include <bits/stdc++.h>
using namespace std;

bool good(int n) {
    string s = to_string(n);
    map<char, int> occu;
    for(int i = 0; i < s.size(); i++) {
        if(occu.find(s[i]) != occu.end()) return false;
        else occu.insert({s[i], 1});
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int y;
    cin >> y;
    y++;
    while(!good(y)) y++;
    cout << y << endl;
    return 0;
}
