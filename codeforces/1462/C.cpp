#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#define pb push_back
#define str to_string
#define len length
#define mxel max_element
#define mnel min_element
#define sum accumulate
using namespace std;
using vi = vector<int>;

void codeforces() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

string qr() {
    string s; cin >> s;
    return s;
}

int qri() {
    return stoi(qr());
}

vi qrvi(int n) {
    vi v;
    for (int i = 0; i < n; i++) v.pb(qri());
    return v;
}

vi::iterator fnd_vi(vi v, int value) {
    return find(v.begin(), v.end(), value);
}

vi::iterator fnd_vi(vi v, int value, vi::iterator start) {
    return find(start, v.end(), value);
}

bool contains_vi(vi v, int value) {
    return fnd_vi(v, value) != v.end();
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a / gcd (a, b) * b;
}

int max_vi(vi v) {
    return *mxel(v.begin(), v.end());
}

int min_vi(vi v) {
    return *mnel(v.begin(), v.end());
}

bool all_eq(vi v, int value) {
    return all_of(v.begin(), v.end(), [&value](int el) { return el == value; });
}

int count_vi(vi v, int value) {
    int n = 0;
    vi::iterator curr = fnd_vi(v, value);
    while(curr != v.end()) {
        curr = fnd_vi(v, value, curr + 2);
        n++;
    }
    return n;
}

int sum_vi(vi v) {
    return sum(v.begin(), v.end(), 0);
}

string solve(int x) {
    if (x > 45) return "-1";
    else if (x < 10) return to_string(x);
    else {
        int sum = 0;
        string res = "";
        for(int i = 9; i > 0; i--) {
            if(sum + i > x) break;
            sum += i;
            res += to_string(i);
        }
        reverse(res.begin(), res.end());
        string add = to_string(x - sum);
        return (add == "0" ? "" : add) + res;
    }
}

int main() {
    codeforces();
    int t = qri();
    while(t--) {
        int x = qri();
        cout << solve(x) << endl;
    }
    return 0;
}