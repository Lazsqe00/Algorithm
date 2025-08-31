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

int N, a[MAX], F[MAX][MAX];
/*
Tỉnh Hà Tĩnh (HSG12-22-23) - Dãy Số Đặc Biệt: https://www.hackerrank.com/contests/test-dethi/challenges/tinh-ha-tinh-hsg12-22-23-day-so-dac-biet/problem
Bài toán đáp án tối ưu trên đoạn con l -> r;
Để tính F[l][r] ta cần dựa trên F[l + 1][r], F[l][r - 1]. Nhận thấy left thì luôn phải <= right
nên ta sẽ for(r) và for(l) phía sau của r. Nhưng for(l) thế nào mới đúng, thì cái đoạn con từ
F[l][r - 1] và F[l + 1][r - 1] luôn tính được dựa vào đoạn r - 1 phía trước nên không cần quan tâm, ta quan tâm 
F[l + 1][r] phải tính trước F[l][r] nghĩa là ta phải for(l) ngược về thì F[l][r] mới tính được dựa trên F[l + 1][r]
*/
int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N;
	FOR(i, 1, N) cin >> a[i];
	
	FOR(r, 1, N){
		REP(l, r, 1){ 
			if(l == r) F[l][r] = 0;
			else{
				if(a[l] == a[r]) F[l][r] = F[l + 1][r - 1];
				else{
					F[l][r] = min(F[l + 1][r], F[l][r - 1]) + 1;
				}
			}
		}
	}
	cout << F[1][N] << endl;
}
