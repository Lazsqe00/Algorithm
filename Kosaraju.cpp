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


int N, M;
vector<int> adj[MAX], revAdj[MAX];
bool visited[MAX];
stack<int> st;

void DFS(int u){
	visited[u] = true;
	for(auto v : adj[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
	st.push(u); // duyet xong u
}

// DFS ap dung tren do thi lat nguoc rev_graph
void DFS_RG(int u){ 
	visited[u] = true;
	for(auto v : revAdj[u]){
		if(!visited[v]){
			DFS_RG(v);
		}
	}
}

void Kosaraju(){
	// B1: Tao ngan xep chua thu tu cac dinh theo sap xep topo
	for(int i = 1; i <= N; i++){
		if(!visited[i]) DFS(i);
	}
	memset(visited, false, sizeof(visited));
	// B3: Lay dinh trong ngan xep
	int d = 0; // dem tplt manh
	while(!st.empty()){
		int top = st.top(); // dinh goc cua tplt manh
		st.pop();
		if(!visited[top]){
			++d;
			DFS_RG(top); 
		}
	}
}


int main(){
	cin >> N >> M;
	FOR(i, 1, M){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		revAdj[y].push_back(x); // lat nguoc canh
	}
	Kosaraju();
}
