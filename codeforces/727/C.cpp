#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << "? " <<  2 << " " << 3 << endl;
    int x;
    cin >> x;
    cout << "? " << 1 << " " << 3 << endl;
    int y;
    cin >> y;
    cout << "? " << 1 << " " << 2 << endl;
    int z;
    cin >> z;
    string output = "! ";
    int second = ((z + x) - y) / 2;
    int first = z - second;
    int third = x - second;
    output += to_string(first) + " " + to_string(second) + " " + to_string(third);
    int last = third;
    for(int i = 2; i < n-1; i++) {
        cout << "? " << i + 1 << " " << i + 2 << endl;
        int s;
        cin >> s;
        output += " " + to_string(s-last);
        last = s-last;
    }
    cout << output << endl;
    return 0;
}
