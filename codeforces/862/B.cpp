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
#define be(a) a.begin(), a.end()
#define fill_vi(a, n, v) a = vector<int>(n, v);
#define uvvu(g, u, v) g[u].push_back(v); g[v].push_back(u);
#define VISITED 1
#define UNVISITED 0
#define INF INT32_MAX
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

graph g;
vi states, colors;
ll r = 0, b = 0;

void bfs(int u) {
    queue<int> q; q.push(u);
    fill_vi(states, g.size(), UNVISITED)
    fill_vi(colors, g.size(), 0)
    states[u] = VISITED;
    r++;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int i = 0; i < g[x].size(); i++) {
            int to = g[x][i];
            if(states[to] == UNVISITED) {
                states[to] = VISITED;
                if(!colors[x]) b++;
                else r++;
                colors[to] = !colors[x];
                q.push(to);
            }
        }
    }
}

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

int main() {
    int n; cin >> n;
    g = graph(n); --n;
    EACHI(n) {
        int u, v; cin >> u >> v; u--; v--;
        uvvu(g, u, v)
    }
    bfs(0);
    cout << r * b - n << endl;
	return 0;
}
