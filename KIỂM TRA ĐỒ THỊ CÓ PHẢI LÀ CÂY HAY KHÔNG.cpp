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
Một đồ thị N đỉnh là một cây, nếu như nó có đúng N-1 cạnh và giữa 2 đỉnh bất kì, chỉ tồn tại duy nhất 1 đường đi giữa chúng.
Cho một đồ thị N đỉnh và N-1 cạnh, hãy kiểm tra đồ thị đã cho có phải là một cây hay không?

Với mỗi test, in ra “YES” nếu đồ thị đã cho là một cây, in ra “NO” trong trường hợp ngược lại.
*/

int T, N, visited[MAX];
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
		cin >> N;
		FOR(i, 1, N - 1){
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
		if(ok) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}
