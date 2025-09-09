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
int N, cnt = 0, b[5], visited[MAX], res = INT_MAX;
struct node{
	int u, v, w;
};
int F[MAX][MAX];
void init_floy(){
	FOR(i, 1, N){
		FOR(j, 1, N){
			if(i == j) F[i][j] = 0;
			else F[i][j] = oo;
		}
	}
}
void floy(){
	FOR(k, 1, N){
		FOR(i, 1, N){
			FOR(j, 1, N){
				F[i][j] = min(F[i][j], F[i][k] + F[k][j]);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N;
	FOR(i, 1, 4) cin >> b[i]; 
	init_floy();
	int u, v, w; 
	while(cin >> u >> v >> w){
		F[u][v] = F[v][u] = w;
	} 
	floy();
}
