#include <bits/stdc++.h>
using namespace std;

// 💖 Hi, thanks for using ICIE! 💖
// 🔧 To use a custom code template, press Ctrl+Shift+P and select "ICIE Template configure" from the list 🔧
// 📝 If you spot any bugs or miss any features, create an issue at https://github.com/pustaczek/icie/issues 📝

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string abc = "abc";
        int ind = 0;
        while(n--) {
            cout << abc[ind];
            ind++;
            if(ind == 3) ind = 0;
        }
        cout << endl;
    }
}
