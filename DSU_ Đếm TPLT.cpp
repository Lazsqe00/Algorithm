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

int par[MAX], sz[MAX];
int T, N, M, cnt;
vector<int> adj[MAX];


int find(int v){
	if(v == par[v]) return v;
	return par[v] = find(par[v]);
}

void init_DSU(){
	FOR(i, 1, N){
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


int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> T;
	while(T--){
		memset(par, 0, sizeof(par));
		memset(sz, 0, sizeof(sz));
		cin >> N >> M;
		init_DSU();
		FOR(i, 1, M){
			int x, y; cin >> x >> y;
			Union(x, y);
		}
		int cnt = 0;
		FOR(i, 1, N){
			if(i == par[i]) ++cnt;
		}
		FOR(i, 1, N) adj[i].clear();
		cout << cnt << endl;
	}
	
}
