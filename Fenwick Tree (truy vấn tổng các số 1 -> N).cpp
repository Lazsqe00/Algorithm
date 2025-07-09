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
const int MAX = 5e5 + 5;

/*
Mỗi phần tử trong mảng bit sẽ lưu các phần tử trong đoạn nào đó của mảng a.
BIT[10] = 1010 -> lấy số 1 đầu tiên bên phải -> là 2^1 -> 2 phần tử là a[10] + a[9]
Nếu i là số lẻ -> BIT[i] lưu a[i] 
Tổng các phần tử từ vị trí 1 -> 14, ta phân tích 14 = 2^3 + 2^2 + 2^1 -> BIT[2^3] + BIT[2^3 + 2^2] + BIT[2^3 + 2^2 + 2^1]

// Tạo cây 
- Mảng a có n phần tử thì mảng BIT[] cũng sẽ có n phần tử
Dựa vào chỉ số trong mảng a[] ta update dần các phần tử trong mảng BIT. ví dụ a[3] -> bắt đầu từ 3
-> 011 -> lấy bit 1 cuối cùng là 001 -> cộng lại ra chỉ số tiếp theo -> 100 -> rồi lấy 100 + 100 -> 1000 

Để tìm ra BIT 1 đầu tiên ở bên phải quả của một số x -> ta lấy x AND -x. Rồi lấy x += BIT 1 đầu tiên bên phải
-> suy ra để tìm chỉ số tiếp theo x += x & -x

Tính tổng phần tử từ vị trí 1 -> 13  = 1101 = 2^3 + 2^2 + 2^0 -> BIT[2^3] + BIT[2^3 + 2^2] + BIT[2^3 + 2^2 + 2^0] = BIT[8] + BIT[12] + BIT[13]
Tổng phần tử tử vị trí 13 chắc chắn có BIT[13] rồi -> để tìm vị trí tiếp theo thay vì như trên cộng BIT 1 bên phải
thì ta trừ đi BIT 1 bên phải -> 13 = 1101 - 0001 = 1100 = 12 là BIT[12]
*/

ll N, Q, a[MAX], BIT[MAX];

// vi tri x cong them 1 luong value don vi
void update(int x, int val){
	while(x <= N){
		BIT[x] += val;
		x = x + (x & (-x)); // ra chi so tiep theo trong mang BIT
	}
}

// truy van tinh tong phan tu, tu vi tri 1 -> x
ll get(int x){
	ll res = 0;
	while(x >= 1){
		res += BIT[x];
		x = x - (x & (-x));
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N >> Q;
	FOR(i, 1, N){
		cin >> a[i];
		update(i, a[i]); // nhung vi tri tiep theo chua a[i] cung se dc update
	}
	while(Q--){
		int type; cin >> type;
		int x, y; cin >> x >> y;
		if(type == 1) update(x, y);
		else cout << get(y) - get(x - 1) << endl; // 1 -> y trừ cho 1 -> (x - 1) thì ra từ x -> y
	}
}
