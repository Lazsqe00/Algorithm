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

int T, N, M, sta[MAX], low[MAX], visited[MAX], cnt;
vector<int> adj[MAX];
int num_child; // dem so luong con cua node goc
set<int> dt; // dung set de khong trung lai dinh nhieu lan
/*
Cho đồ thị vô hướng liên thông G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy đưa ra tất cả các đỉnh trụ của đồ thị?
Tarjan đỉnh trụ, cạnh cầu có hướng hay vô hướng đều như nhau
*/

void DFS(int u, int par){
	visited[u] = true;
	sta[u] = low[u] = ++cnt;
	for(auto v : adj[u]){
		if(!visited[v]){
			if(par == 0) ++num_child;
			DFS(v, u);
			low[u] = min(low[u], low[v]); 
			if(low[v] >= sta[u] && par != 0){ // v k co duong di toi to tien cua u
				dt.insert(u); // dinh u dc nhet vao nhieu lan
			}
		}
		else if(v != par){
			low[u] = min(low[u], sta[v]); 
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
		memset(sta, 0, sizeof(sta));
		memset(low, 0, sizeof(low));
		cnt = 0, num_child = 0;
		// do thi lien thong
		DFS(1, 0);
		if(num_child > 1) dt.insert(1);
		FOR(i, 1, N) adj[i].clear();
		for(auto v : dt) cout << v << " ";
		cout << endl;
		dt.clear();
	}
}
