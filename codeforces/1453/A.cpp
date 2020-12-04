#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> read_ints(int n) {
    vector<int> res;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        res.push_back(a);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n; cin >> m;
        vector<int> down = read_ints(n);
        vector<int> left = read_ints(m);
        int res = 0;
        for (int i = 0; i < down.size(); i++) {
            if (std::find(left.begin(), left.end(), down[i]) != left.end())
                res++;
        }
        cout << res << endl;
    }
    return 0;
}