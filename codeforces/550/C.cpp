#include <bits/stdc++.h>
using namespace std;

bool notfound = true;

void check_ans(int curr) {
    if(curr % 8 == 0 && notfound) {
        cout << "YES" << endl;
        cout << curr << endl;
        notfound = false;
    }
}

int main() {
    string s;
    cin >> s;
    int n = (int)s.size();
    for(int i = 0; i < n && notfound; i++) {
        check_ans(s[i] - '0');
        for(int j = i + 1; j < n && notfound; j++) {
            check_ans(stoi(string(1, s[i]) + s[j]));
            for(int k = j + 1; k < n && notfound; k++)
                check_ans(stoi(string(1, s[i]) + s[j] + s[k]));
        }
    }
    if(notfound) cout << "NO" << endl;
    return 0;
}
