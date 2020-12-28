#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int x = 0;
    while(n--) {
        string s; cin >> s;
        if(s.find('+') != string::npos) x++;
        else x--;
    }
    cout << x << endl;
    return 0;
}