#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using lli = pair<unsigned long long, int>;
using ill = pair<int, unsigned long long>;
using wgraph = vector<vector<ill>>;

wgraph g;
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    g = wgraph(n);
    for(int i = 0; i < m; i++) {
        unsigned long long u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    priority_queue<lli, vector<lli>, greater<lli>> q; q.push({0, n-1});
    vector<unsigned long long> dist(n, 1e18), path(n, -1);
    dist[n-1] = 0;
    path[n-1] = -1;
    while(!q.empty()) {
        lli front = q.top();
        q.pop();
        unsigned long long d = front.first, u = front.second;
        if(d > dist[u]) continue;
        for(int j = 0; j < (int)g[u].size(); j++) {
            ill v = g[u][j];
            if(dist[u] + v.second >= dist[v.first]) continue;
            dist[v.first] = dist[u] + v.second;
            path[v.first] = u;
            q.push({dist[v.first], v.first});
        }
    }
    unsigned long long v = 0;
    if(path[v] == -1) cout << -1 << endl;
    else {
        while(v != n - 1) {
            cout << v + 1 << " ";
            v = path[v];
        }
        cout << n;
    }
    return 0;
}

