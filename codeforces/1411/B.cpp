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
    while(t--) {
        long long n; cin >> n;
        long long res = n;
        bool found = false;
        while(!found) {
            string s = to_string(res);
            for(int i = 0; i < s.length(); i++) {
                if(s[i] != '0') {
                    if(res % stoi(string(1, s[i])) != 0) {
                        break;
                    }
                }
                if(i == s.length() - 1) found = true;
            }
            if(found) break;
            else res++;
        }
        cout << res << endl;
    }
    return 0;
}