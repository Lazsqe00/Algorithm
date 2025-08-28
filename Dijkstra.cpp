#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int,int> ii;
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define REP(i, a, b) for(int i = a; i >= b; --i)
#define fi first
#define se second
#define pb push_back
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const int oo = LONG_LONG_MAX;
vector<ii> adj[MAX];
int N, M, s, t;
ll d[MAX];

void dijkstra(int s, int t){
	FOR(i, 1, N) d[i] = oo;
	d[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({0, s});
	while(!pq.empty()){
		int du = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if(du > d[u]) continue;
		for(auto e : adj[u]){
			int dv = e.fi, v = e.se;
			if(d[u] + dv < d[v]){
				d[v] = d[u] + dv;
				pq.push({d[v], v});
			}
		}
	}
	if(d[t] == oo) cout << -1 << endl;
	else cout << d[t] << endl;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N >> M >> s >> t;
	FOR(i, 1, M){
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({w, y});
		adj[y].push_back({w, x});
	}
	dijkstra(s, t);
}
