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
Cho đồ thị vô hướng liên thông G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy kiểm tra xem đồ thị có đường đi Euler hay chu trình Euler hay không?
Đưa ra 1, 2, 0 kết quả mỗi test theo từng dòng tương ứng với đồ thị có đường đi Euler, chu trình Euler và trường hợp không tồn tại.
*/

int T, N, M, deg[MAX];

int main(){
	cin >> T;
	while(T--){
		cin >> N >> M;
		memset(deg, 0, sizeof(deg));
		FOR(i, 1, M){
			int x, y; cin >> x >> y;
			deg[x]++; deg[y]++;
		}
		int d = 0; // dem cac dinh co ban bac le
		FOR(i, 1, N){
			if(deg[i] % 2 != 0) ++d;
		}
		if(d == 0) cout << "2" << endl;
		else{
			if(d == 2) cout << "1" << endl;
			else cout << "0" << endl;
		}
	}
}
