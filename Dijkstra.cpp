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
const ll oo = LONG_LONG_MAX;

int N, M, s, t; // s la dinh bat dau, t la dinh ket thua
vector<ii> adj[MAX];
ll d[MAX];

void dijkstra(int s){
	priority_queue<ii, vector<ii>, greater<ii>> pq; // lay ra phan tu nho nhat
	FOR(i, 1, N) d[i] = oo;
	d[s] = 0;
	pq.push({s, 0});
	while(!pq.empty()){
		int u = pq.top().first;
		int dis = pq.top().second;
		pq.pop();
		if(dis > d[u]) continue;
		for(auto e : adj[u]){
			int v = e.fi, uv = e.se;
			if(d[v] > d[u] + uv){
				d[v] = d[u] + uv;
				pq.push({v, d[v]});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N >> M >> s >> t;
	FOR(i, 1, M){
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	dijkstra(s);
	cout << d[t] << endl;
}
