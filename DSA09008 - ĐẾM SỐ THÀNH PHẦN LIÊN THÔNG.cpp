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

// dem so thanh phan lien thong do thi, code trau
int T, N, M, visited[MAX];
vector<int> adj[MAX];

void DFS(int u){
	visited[u] = true;
	for(auto v : adj[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
}

int main(){
	cin >> T;
	while(T--){
		cin >> N >> M;
		FOR(i, 1, M){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		memset(visited, false, sizeof(visited));
		int cnt = 0;
		FOR(i, 1, N){
			if(!visited[i]){
				cnt++;
				DFS(i);
			}
		}
		FOR(i, 1, N) adj[i].clear();
		cout << cnt << endl;
	}
}
