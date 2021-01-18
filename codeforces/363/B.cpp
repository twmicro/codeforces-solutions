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
#define VISITED 1
#define UNVISITED 0
#define inf 1000000000
#define be(v) v.begin(), v.end()
#define uvvu(g, u, v) u--; v--; g[u].push_back(v); g[v].push_back(u);
#define uvwwvu(wg, u, v, w) u--; v--; wg[u].push_back(mp(v, w)); wg[v].push_back(mp(u, w));
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using dijque = priority_queue<ii, vector<ii>, greater<ii>>;
using graph = vector<vector<int>>;
using wgraph = vector<vector<ii>>;

void bubble_sort(vi *a) {
    for(int i = 0; i < (*a).size(); i++) {
        for(int j = i + 1; j < (*a).size(); j++) {
            if((*a)[i] > (*a)[j]) 
                (*a)[i] ^= ((*a)[j] ^= ((*a)[i] ^= (*a)[j]));
        }
    }
}

bool binary_search(vi a, int v) {
    int l = 0, r = a.size() - 1, m = (l + r) / 2;
    while(l <= r) {
        if(a[m] == v) return true;
        if(a[m] > v) r = m - 1;
        else l = m + 1;
        m = (l + r) / 2;
    }
    return false;
}

int gcd(int a, int b) {
    return a == 0 || b == 0 ? a ^ b : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

struct segtree {
    int size;
    vector<int> tree;
    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.assign(2 * size - 1, 0);
    }

    void build(vi a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < a.size())
                tree[x] = a[lx];
        } else {
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        }
    }

    void build(vi a) {
        init(a.size());
        build(a, 0, 0, size);
    }
    
    void set(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) tree[x] = v;
        else {
            int m = (lx + rx) / 2;
            if(i < m) set(i, v, 2 * x + 1, lx, m);
            else set(i, v, 2 * x + 2, m, rx);
            tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        }
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int sum(int l, int r, int x, int lx, int rx) {
        if(l >= rx || r <= lx) return 0;
        else if(lx >= l && rx <= r) return tree[x];
        else {
            int m = (lx + rx) / 2;
            return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
        }
    }

    int sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

class dsu {
    public:
        vector<int> p;
        int n;

        dsu(int _n) : n(_n) {
            p.resize(n);
            iota(be(p), 0);
        }

        inline int get(int u) {
            return p[u] == u ? u : (p[u] = get(p[u]));
        }

        inline bool unite(int u, int v) {
            u = get(u);
            v = get(v);
            if(u != v) {
                p[u] = v;
                return true;
            }
            return false;
        }
};



int palindromity(string s, int l, int r) {
    if(l == r) return 1;
    else if(l + 1 == r) return s[l] == s[r] ? 2 : 1;
    else if(s[l] == s[r]) return 2 + palindromity(s, l + 1, r - 1);
    else return max(palindromity(s, l, r - 1), palindromity(s, l + 1, r));
}

int palindromity(string s) {
    return palindromity(s, 0, s.size() - 1);
}

template <typename T1, typename T2>
void unp(pair<T1, T2> p, T1 *f, T2 *s) {
    (*f) = p.first;
    (*s) = p.second;
}

template <typename T1, typename T2, typename T3>
void unpp(pair<T1, pair<T2, T3>> p, T1 *f, T2 *s, T3 *t) {
    (*f) = p.first;
    (*s) = p.second.first;
    (*t) = p.second.second;
}

graph g;
wgraph wg;
vi states, colors, paths, ts;

vi ford_bellman(int s) {
    vi res(wg.size(), inf);
    res[s] = 0;
    for(int i = 0; i < wg.size() - 1; i++) {
        for(int u = 0; u < wg.size(); u++) {
            for(int j = 0; j < wg[u].size(); j++) {
                int to, w; unp(wg[u][j], &to, &w);
                res[to] = min(res[to], res[u] + w);
            }
        }
    }
    return res;
}

void dfs(int u) {
    states[u] = VISITED;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(states[v] == UNVISITED)
            dfs(v);
    }
}

void topological_sort(int u) {
    states[u] = VISITED;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(states[v] == UNVISITED)
            dfs(v);
    }
    ts.add(u);
}

void bfs(int s) {
    queue<int> q; q.push(s);
    states = vi(g.size(), UNVISITED);
    states[s] = VISITED;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if(states[v] == UNVISITED) {
                states[v] = VISITED;
                q.push(v);
            }
        }
    }
}

bool isBipartite() {
    bool bipartite = true;
    states = vi(g.size(), UNVISITED);
    colors = vi(g.size(), 0);
    for(int s = 0; s < g.size(); s++) {
        if(states[s] == UNVISITED) {
            queue<int> q; q.push(s);
            states[s] = VISITED;
            while(!q.empty() && bipartite) {
                int u = q.front(); q.pop();
                for(int i = 0; i < g[u].size(); i++) {
                    int v = g[u][i];
                    if(states[v] == UNVISITED) {
                        states[v] = VISITED;
                        colors[v] = !colors[u];
                        q.push(v);
                    }
                    else if(states[v] == VISITED && colors[v] == colors[u]) {
                        bipartite = false;
                        break;
                    }
                }
            }
        }
    }
    return bipartite;
}

vi sssp_bfs(int s, int d) {
    vi res;
    queue<int> q; q.push(s);
    states = vi(g.size(), UNVISITED);
    paths = vi(g.size(), -1);
    states[s] = VISITED;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if(states[v] == UNVISITED) {
                states[v] = VISITED;
                paths[v] = u;
                q.push(v);
            }
        }
    }
    if(paths[d] == -1) return res;
    while(d != s) {
        res.add(d);
        d = paths[d];
    }
    res.add(s);
    reverse(be(res));
    return res;
}

int cruscal(vector<iii> el, int n) {
    sort(el.begin(), el.end());
    dsu d(n);
    int min_cost = 0;
    for(int i = 0; i < el.size(); i++) {
        int u, v, w; unpp(el[i], &w, &u, &v);
        if(d.get(u) != d.get(v)) {
            min_cost += w;
            d.unite(u, v);
        }
    }
    return min_cost;
}

vi dijkstra(int s) {
    vi dist(wg.size(), inf);
    priority_queue<ii, vector<ii>, greater<ii>> q; q.push({0, s});
    dist[s] = 0;
    while(!q.empty()) {
        int d, u; unp(q.top(), &d, &u); q.pop();
        if(dist[u] < d) continue;
        for(int i = 0; i < wg[u].size(); i++) {
            int v, w; unp(wg[u][i], &v, &w);
            if(dist[v] <= dist[u] + w) continue;
            dist[v] = dist[u] + w;
            q.push({dist[v], v});
        }
    }
    return dist;
}

// Note using graph not as an adjacency list but as an adjacency matrix!
// So it can be used for weighted graphs where |E| <= 400
graph floyd_warshall(graph adj) {
    for(int k = 0; k < g.size(); k++)
        for(int i = 0; i < g.size(); i++)
            for(int j = 0; j < g.size(); j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    return adj;
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

vi c;
void prepare(string s) {
    for(int i = 1; i < s.size(); i++)
        if(s[i] == s[i - 1])
            c[i] = c[i - 1] + 1;
        else
            c[i] = c[i - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/
	// Here will be my code
    int n, k; cin >> n >> k;
    vi a = read_vi(n);
    int mn = INT32_MAX;
    int at = 0;
    int s = 0;
    for(int i = 0; i < n; i++) {
        if(i < k - 1) {
            s += a[i];
            continue;
        }
        s += a[i];
        if(s < mn) {
            mn = s;
            at = i - k + 1;
        }
        s -= a[i - k + 1];
    }
    cout << at + 1 << endl;
	return 0;
}
