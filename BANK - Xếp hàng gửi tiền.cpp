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
Lời giải quy hoạch động:
+ Gọi F[i][k] là giá trị lớn nhất thu được khi xét tới khách hàng thứ i ở thời gian k. Do có thao tác sắp xếp vì vậy khi xét tới khách
hàng thứ i :
- Ví dụ Khách hàng có t = 5 chẳng hạn có thể làm được tại bất kỳ thời gian nhỏ hơn hoặc bằng nó. Do đó ta sẽ duyệt từ 1 -> time đợi của khách hàng.  
Ta có 2 lựa chọn tại mỗi thời gian mà khách hàng thứ i có thể đợi được:
+ Nếu tại thời gian đó không chọn khách hàng thứ i: F[i][k] = F[i - 1][k] // đáp án của dãy con trước đó
+ Nếu khi thêm khách hàng thứ i vào khoảng thời gian đó thì nó sẽ là bằng F[i - 1][k - 1] (i - 1 là dựa trên đáp án của dãy trước đó, k - 1 vì 
thời gian phải lùi về 1 giờ) rồi + a[i].val. Và giá trị này > F[i - 1][k].

Đáp án là max của tất cả các thời gian khi xét xong N người F[N][time từ 1 -> maxTime] 
*/
struct cust{
	int t, val, id;
};
int N, F[10001][1001]; 
cust a[MAX];

bool cmp(cust a, cust b){
	if(a.t != b.t) return a.t < b.t;
	else return a.val < b.val;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N;
	FOR(i, 1, N){
		cin >> a[i].val >> a[i].t;
		a[i].t += 1;
	}
	sort(a + 1, a + N + 1, cmp);
	int ans = 0;
	FOR(i, 1, N){
		FOR(k, 1, a[i].t){
			F[i][k] = max(F[i - 1][k], F[i - 1][k - 1] + a[i].val);
		}
	}
	FOR(k, 1, 1000)  ans = max(ans, F[N][k]);
	cout << ans << endl;
}
