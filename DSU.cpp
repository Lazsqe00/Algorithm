int par[MAX], sz[MAX];
vector<int> adj[MAX];

// Khi nhập cạnh x, y. Mình Union 2 đỉnh x, y lại

int find(int v){
	if(v == par[v]) return v;
	return par[v] = find(par[v]);
}
// chú ý rất hay quên init_DSU
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
