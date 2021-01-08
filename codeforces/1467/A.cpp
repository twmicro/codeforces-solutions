#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <numeric>
#define INCRI(start, end, step) for(int i = start; i < end; i += step)
#define INCRJ(start, end, step) for(int j = start; j < end; j += step)
#define INCRX(start, end, step) for(int x = start; x < end; x += step)
#define INCRY(start, end, step) for(int y = start; y < end; y += step)
#define INCRZ(start, end, step) for(int z = start; z < end; z += step)
#define DECRI(start, end, step) for(int i = start; i >= end; i -= step)
#define DECRJ(start, end, step) for(int j = start; j >= end; j -= step)
#define DECRX(start, end, step) for(int x = start; x >= end; x -= step)
#define DECRY(start, end, step) for(int y = start; y >= end; y -= step)
#define DECRZ(start, end, step) for(int z = start; z >= end; z -= step)
#define NEXTI(start, end) INCRI(start, end, 1)
#define NEXTJ(start, end) INCRJ(start, end, 1)
#define NEXTX(start, end) INCRX(start, end, 1)
#define NEXTY(start, end) INCRY(start, end, 1)
#define NEXTZ(start, end) INCRZ(start, end, 1)
#define BACKI(start, end) DECRI(start, end, 1)
#define BACKJ(start, end) DECRJ(start, end, 1)
#define BACKX(start, end) DECRX(start, end, 1)
#define BACKY(start, end) DECRY(start, end, 1)
#define BACKZ(start, end) DECRZ(start, end, 1)
#define EACHI(n) NEXTI(0, n)
#define EACHJ(n) NEXTJ(0, n)
#define EACHX(n) NEXTX(0, n)
#define EACHY(n) NEXTY(0, n)
#define EACHZ(n) NEXTZ(0, n)
#define DOWNI(n) BACKI(n, 0)
#define DOWNJ(n) BACKJ(n, 0)
#define DOWNX(n) BACKX(n, 0)
#define DOWNY(n) BACKY(n, 0)
#define DOWNZ(n) BACKZ(n, 0)
#define EACHSI(n, step) INCRI(0, n, step)
#define EACHSJ(n, step) INCRJ(0, n, step)
#define EACHSX(n, step) INCRX(0, n, step)
#define EACHSY(n, step) INCRY(0, n, step)
#define EACHSZ(n, step) INCRZ(0, n, step)
#define DOWNSI(n, step) DECRI(n, 0, step)
#define DOWNSJ(n, step) DECRJ(n, 0, step)
#define DOWNSX(n, step) DECRX(n, 0, step)
#define DOWNSY(n, step) DECRY(n, 0, step)
#define DOWNSZ(n, step) DECRZ(n, 0, step)
#define add push_back
#define put insert
#define mp make_pair
#define sum accumulate
#define mxel max_element
#define mnel min_element
#define str to_string
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using graph = vector<vector<int>>;

vi read_vi(int n) {
	vi v(n, 0); 
	EACHI(n) cin >> v[i];
	return v;
}

vll read_vll(int n) {
	vll v(n, 0); 
	EACHI(n) cin >> v[i];
	return v;
}

void print(vi v) {
	EACHI(v.size()) {
		if(i != 0) cout << " ";
		cout << v[i];
    }
    cout << endl;
}

void print(vll v) {
	EACHI(v.size()) {
		if(i != 0) cout << " ";
		cout << v[i];
    }
    cout << endl;
}


ll sum_all(int n) {
	return n % 2 == 0 ? n / 2 * (n + 1) : n * ((n + 1) / 2);
}

ll sum_all(ll n) {
	return n % 2 == 0 ? n / 2 * (n + 1) : n * ((n + 1) / 2);
}

string solve(int n) {
    if(n == 1) return "9";
    else if(n == 2) return "98";
    string res = "989";
    string p = "0123456789";
    n -= 3;
    for(int i = 0; i < n; i++) {
        res += p[i % 10];
    }
    return res;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// Here will be my code
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << solve(n) << endl;
    }
	return 0;
}
