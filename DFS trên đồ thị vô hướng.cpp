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

vector<int> adj[MAX];
bool visited[MAX];

void dfs(int u) {
	visited[u] = true;
	for (int v : adj[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	
	FOR(i, 1, M){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	fill(visited, visited + N + 1, false);
	dfs(1);
	
	return 0;
}

