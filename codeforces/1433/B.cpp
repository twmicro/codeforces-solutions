#include <iostream>
#include <vector>
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a = read_ints(n);
        int iFirst1 = 0;
        int iLast1 = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == 1) {
                iFirst1 = i;
                break;
            }
        }

        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] == 1) {
                iLast1 = i;
                break;
            }
        }
        a = { a.begin() + iFirst1, a.begin() + iLast1 + 1 };
        int z = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == 0) z++;
        }
        cout << z << endl;
    }
}