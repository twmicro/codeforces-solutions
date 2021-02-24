#include <bits/stdc++.h>
using namespace std;

string s = "";
int n, m;
int add(bool strategy, int amount, int i) {
    if(strategy && i < n - 1) amount = add(strategy, amount, i + 1);
    s[i] = s[i] + min(amount, 9);
    amount -= min(amount, 9);
    if(!strategy && amount > 0) add(strategy, amount, i + 1);
    return amount;
}

int main() {
    cin >> n >> m;
    if(n * 9 < m) cout << -1 << " " << -1 << endl;
    else if(n == 1 && m == 0) cout << 0 << " " << 0 << endl;
    else if(m == 0) cout << -1 << " " << -1 << endl;
    else {
        s = "1" + string(n - 1, '0');
        add(true, m - 1, 0);
        cout << s << " ";
        s = string(n, '0');
        add(false, m, 0);
        cout << s << endl;
    }
    return 0;
}
