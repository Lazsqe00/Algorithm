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
const int MAX = 1005;

int a[MAX][MAX]; // Ma tran ke
bool visited[MAX];
int N, M; 

void dfs(int u) {
	visited[u] = true;
		FOR(v, 1, N){
		if (a[u][v] == 1 && !visited[v]) {
			dfs(v);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; ++i) {
		int u, v;
		cin >> u >> v;
		a[u][v] = a[v][u] = 1;
	}
	dfs(1); 
	return 0;
}
