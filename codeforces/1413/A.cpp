#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void run_case() {
    int n; cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++) { 
        int ai; cin >> ai;
        a.push_back(ai);
    }

    for(int i = 1; i < n; i += 2) {
        cout << -a[i] << " ";
        cout << a[i - 1];
        if (i == n - 1) cout << endl;
        else cout << " ";
    }
}

int main() {
    int t; cin >> t;
    while(t--) run_case();
    return 0;
}