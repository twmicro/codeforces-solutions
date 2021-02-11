#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        string s = to_string(n);
        int c = 0;
        for(int i = 0; i < s.size(); i++)
            if(s[i] != '0')
                c++;
        cout << c << "\n";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '0') {
                cout << s[i];
                for(int j = i + 1; j < s.size(); j++)
                    cout << "0";
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
