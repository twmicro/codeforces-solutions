#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    int n; cin >> n;
    cout << n / 2 << endl;
}

int main() {
    int t; cin >> t;
    while(t--) run_case();
    return 0;
}