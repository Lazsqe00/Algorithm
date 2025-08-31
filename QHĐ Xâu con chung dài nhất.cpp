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

int N, F[MAX][MAX];
/*
gọi F[i][j] là độ dài của xâu con chung xét tới vị trí thứ i trong chuỗi s, và vị trí thứ j trong chuỗi t
Nếu s[i] == t[j] => F[i][j] = F[i - 1][j - 1] + 1
Ngược lại rơi 2 TH, F[i][j] = max(F[i - 1][j], F[i][j - 1]);
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	string s, t; cin >> s >> t;
	s = " " + s;
	t = " " + t;
	FOR(i, 1, s.size() - 1){
		FOR(j, 1, t.size() - 1){
			if(s[i] == t[j]){
				F[i][j] = F[i - 1][j - 1] + 1;
			}
			else{
				F[i][j] = max(F[i - 1][j], F[i][j - 1]);
			}
		}
	}
	cout << F[s.size() - 1][t.size() - 1] << endl;
}
