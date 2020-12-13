#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
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
    for (int i = 0; i < n; i++) { 
        int el; cin >> el;
        v.pb(el);
    }
    return v;
}

vi::iterator fnd_vi(vi v, int value) {
    return find(v.begin(), v.end(), value);
}

vi::iterator fnd_vi(vi v, int value, vi::iterator start) {
    return find(start, v.end(), value);
}

bool contains_vi(vi v, int value) {
    return fnd_vi(v, value) < v.begin() + v.size();
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

int main() {
    codeforces();
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        set<int> res;
        while (n--) {
            int el; cin >> el;
            res.insert(el);
        }
        cout << res.size() << endl;
    }
    return 0;
}