#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define REP(i, a, b) for(int i = a; i >= b; --i)
#define fi first
#define se second
#define pb push_back
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
using ll = long long;

/*
Bài toán đưa về tìm đoạn con w có tổng lớn nhất trong mảng a và tìm đoạn con h có tổng lớn nhất
trong mảng b. Ta dùng cửa sổ trượt trên cả 2 mảng a và b.
*/
int N, M, w, h, a[MAX], b[MAX];

int solve(int x[MAX + 3], int sz, int w){
	int sum = 0;
	FOR(i, 1, w) sum += x[i];
	int rs = sum;
	FOR(i, w + 1, sz){
		sum = sum - x[i - w] + x[i];
		rs = max(rs, sum);
	}
	return rs;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N >> M >> w >> h; 
	FOR(i, 1, N) cin >> a[i];
	FOR(j, 1, M) cin >> b[j];
	cout << 1ll * h *solve(a, N, w) + 1ll * w * solve(b, M, h) << endl;
}
