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
Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh.Hãy kiểm tra xem đồ thị có tồn tại chu trình hay không?
*/

int T, N, M, visited[MAX];
vector<int> adj[MAX];

bool DFS(int u, int par){
	visited[u] = true;
	for(auto v : adj[u]){
		if(!visited[v]){
			if(DFS(v, u)) return true;
		}
		else if(v != par){
			return true;
		}
	}
	return false;
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
		bool ok = false;
		FOR(i, 1, N){
			if(!visited[i]){
				if(DFS(i, 0)){
					ok = true;
				}
			}
		}
		FOR(i, 1, N) adj[i].clear();
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
