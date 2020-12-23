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

int bin_search(vi v, int value) {
    int start = 0;
    int end = v.size() - 1;
    int mid = start + (end - start) / 2;
    while(v[mid] != value) {
        if(start == end) {
            mid = -1;
            break;
        }

        if(v[mid] > value) end = mid - 1;
        else start = mid + 1;
        mid = start + (end - start) / 2;
    }
    return mid;
}



void oc(vi v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
        if(i != v.size() - 1) cout << " ";
        else cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--)  {
        string s; cin >> s;
        if(s.length() <= 10) cout << s << endl;
        else cout << s[0] << s.length() - 2 << s[s.length() - 1] << endl;
    }
    return 0;
}