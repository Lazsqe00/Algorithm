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
Cho đồ thị có hướng G = <V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy kiểm tra xem đồ thị có tồn tại chu trình hay không?

Trong đồ thị có hướng, đỉnh 1 đến đỉnh 2 và đỉnh 2 quay lại đỉnh 1 được xem là 1 chu trình
*/

int T, N, M, color[MAX];
vector<int> adj[MAX];

bool DFS(int u, int par){
	color[u] = 1;
	for(auto v : adj[u]){
		if(color[v] == 0){
			if(DFS(v, u)) return true;
		}
		else if(color[v] == 1){
			return true;
		}
	}
	color[u] = 2; 
	return false;
}

int main(){
	cin >> T;
	while(T--){
		cin >> N >> M;
		FOR(i, 1, M){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
		}
		memset(color, 0, sizeof(color));
		bool ok = false;
		FOR(i, 1, N){
			if(color[i] == 0){
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
