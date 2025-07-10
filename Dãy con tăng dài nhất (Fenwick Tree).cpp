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
Truy vấn nhanh với độ phức tạp NlogN
*/
struct gift{
	int a, w, id;
};
ll N, Q, BIT[MAX], F[MAX];
gift a[MAX];
map<int, int> mp;
void update(int x, ll val){
	while(x <= N){
		BIT[x] = max(BIT[x], val);
		x = x + (x & (-x)); 
	}
}

ll get(int x){
	ll res = 0;
	while(x >= 1){
		res = max(res, BIT[x]);
		x = x - (x & (-x));
	}
	return res;
}

bool cmp_a(gift a, gift b){
	return a.a < b.a;
}

bool cmp_id(gift a, gift b){
	return a.id < b.id;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N;
	FOR(i, 1, N){
		cin >> a[i].a >> a[i].w;
		a[i].id = i;
	}
	// thao tac nen
	sort(a + 1, a + N + 1, cmp_a);
	FOR(i, 1, N){
		if(mp[a[i].a] == 0){
			int x = mp.size();
			mp[a[i].a] = x;
			a[i].a = x;
		}
		else a[i].a = mp[a[i].a];
	}
	sort(a + 1, a + N + 1, cmp_id);
	cout << "ai.a" << endl;
	FOR(i, 1, N) cout << a[i].a << " ";
	cout << endl;
	ll ans = 0;
	// F[i] = max(F[i], F[j] + w[i]);
	FOR(i, 1, N){
		// tim gia lon nhat trong doan 1 den a[i].a - 1
		ll x = get(a[i].a - 1);
		F[i] = x + a[i].w;
		ans = max(ans, F[i]);
		update(a[i].a, F[i]);
	}
	cout << ans << endl;
}
