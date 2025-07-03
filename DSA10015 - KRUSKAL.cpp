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
/*
Cho đồ thị vô hướng có trọng số G=<V, E, W>. Nhiệm vụ của bạn là hãy xây dựng một cây khung nhỏ nhất của đồ thị bằng thuật toán Kruskal.
*/

int par[MAX], sz[MAX];
int T, N, M;
struct edge{
	int u, v, w;
};

bool cmp(edge a, edge b){
	return a.w < b.w;
}
edge adj[MAX];


int find(int v){
	if(v == par[v]) return v;
	return par[v] = find(par[v]);
}

void init_DSU(){
	FOR(i, 1, N){
		sz[i] = 1;
		par[i] = i;
	}
}

bool Union(int a, int b){
	int u = find(a);
	int v = find(b);
	if(u == v) return false; 
	else{
		if(sz[u] >= sz[v]){
			par[v] = u;
			sz[u] += sz[v];
		}
		else{
			par[u] = v;
			sz[v] += sz[u];
		}
	}
	return true;
}


void kruskal(){
	int d = 0;
	sort(adj + 1, adj + M + 1, cmp);
	int ans = 0;
	FOR(i, 1, M){
		if(d == N - 1) break;
		int u = adj[i].u, v= adj[i].v, w = adj[i].w;
		if(Union(u, v)){
			ans += w;
			++d;
		}
	}
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> T;
	while(T--){
		memset(par, 0, sizeof(par));
		memset(sz, 0, sizeof(sz));
		cin >> N >> M;
		init_DSU();
		FOR(i, 1, M){
			cin >> adj[i].u >> adj[i].v >> adj[i].w;
		}
		kruskal();
		cout << endl;
		FOR(i, 1, M) adj[i] = {0, 0, 0};
	}
}
