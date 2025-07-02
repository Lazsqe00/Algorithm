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
Cho đồ thị vô hướng liên thông G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy đưa ra tất cả các cạnh cầu của đồ thị? 
Đưa ra danh sách các cạch cầu của mỗi test theo từng dòng. In ra đáp án theo thứ tự từ điển, theo dạng “a b …” với a < b.
*/

int T, N, M, sta[MAX], low[MAX], visited[MAX], cnt;
vector<int> adj[MAX];
vector<ii> edges;

void DFS(int u, int par){
	visited[u] = true;
	sta[u] = low[u] = ++cnt;
	for(auto v : adj[u]){
		if(!visited[v]){
			DFS(v, u);
			low[u] = min(low[u], low[v]); 
			if(low[v] > sta[u]){ // v k co duong di toi to tien cua u
				edges.push_back({min(u, v), max(u, v)});
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
		FOR(i, 1, N) sort(adj[i].begin(), adj[i].end());
		memset(visited, false, sizeof(visited));
		memset(sta, 0, sizeof(sta));
		memset(low, 0, sizeof(low));
		cnt = 0;
		// do thi lien thong
		DFS(1, 0);
		sort(edges.begin(), edges.end());
		for(auto edge : edges){
			cout << edge.fi << " " << edge.se << " ";
		}
		cout << endl;
		FOR(i, 1, N) adj[i].clear();
		edges.clear();
	}
}
