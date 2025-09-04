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
const int MAX = 1e3 + 5;
const int oo = 1e9;

int N, M; 
int a[MAX][MAX], b[MAX][MAX], d[MAX][MAX];
vector<ii> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
struct dinh{
	int i, j, d;
};
struct cmp{
	operator() (dinh a, dinh b){
		return a.d > b.d;
	}
};

priority_queue<dinh, vector<dinh>, cmp> pq;

bool insize(int i, int j){
	return i >= 1 && i <= N && j >= 1 && j <= M;
}

void Dijkstra(int u, int v){
	FOR(i, 1, N) FOR(j, 1, M) d[i][j] = oo;
	d[u][v] = 0;
	dinh e = {u, v, 0};
	pq.push(e);
	while(!pq.empty()){
		dinh u = pq.top(); pq.pop();
		int i = u.i, j = u.j, dij = u.d;
		if(dij > d[i][j]) continue;
		for(auto v : dir){
			int i1 = i + v.fi, j1 = j + v.se;
			int time = 0;
			if(insize(i1, j1)){
				if(v.fi == 0 && v.se == 1) time = a[i][j];
				else if(v.fi == 1 && v.se == 0) time = b[i][j];
				else if(v.fi == -1 && v.se == 0) time = b[i1][j1];
				else time = a[i1][j1];
				if(d[i1][j1] > d[i][j] + time){
					d[i1][j1] = d[i][j] + time;
					pq.push({i1, j1, d[i1][j1]});
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N >> M;
	FOR(i, 1, N) FOR(j, 1, M - 1) cin >> a[i][j]; 
	FOR(i, 1, N - 1) FOR(j, 1, M) cin >> b[i][j];
	Dijkstra(1, 1);
	cout << d[N][M] << endl;
}
    
