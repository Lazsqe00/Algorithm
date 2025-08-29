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

int N, M, visited[MAX], disc[MAX], low[MAX], cnt;
vector<int> adj[MAX];
int res[MAX];
// chon dinh u lam goc
/*
Minh họa thuật toán Tarjan bỏ từng đỉnh của đồ thị và liệt kê số lượng tplt nếu bỏ đi đỉnh đó.
Nếu u là đỉnh trụ, ta chỉ cần tìm tất cả các nhánh v thỏa mãn u là đỉnh trụ thì nhánh v đó là 1 tplt riêng biệt + 1 nhánh tổ tiên của u phía trước.
Nếu các đỉnh nằm chung 1 chu trình thì visited của các đỉnh đó đều là true, khi đó đỉnh gốc sẽ không ghé lại 1 trong các đỉnh đó, số lượng biến child sẽ là số
nhánh của đỉnh đó. Nếu đỉnh gốc > 2 nhánh thì 100% đỉnh gốc là đỉnh trụ và số nhánh chính là số tplt.
*/
void DFS(int u, int par){
	visited[u] = true;
	disc[u] = low[u] = cnt++;
	int child = 0, d = 0;
	bool ok = false;
	for(auto v : adj[u]){
		if(!visited[v]){
			child++; // dem so nhanh
			DFS(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= disc[u] && par != 0){
				++d;
			}
		}
		else if(v != par){
			low[u] = min(low[u], disc[v]); 
		}
	}
	if(par == 0){
		if(child >= 2) res[u] = child;
		else res[u] = 1;
	}
	else{
		if(d > 0) res[u] = d + 1;
		else res[u] = 1;
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N >> M;
	FOR(i, 1, M){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
	DFS(1, 0);
	FOR(i, 1, N) cout << res[i] << endl;
}
