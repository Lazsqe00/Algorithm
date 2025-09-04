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

int N, BIT[MAX], F[MAX];
ii a[MAX];
/*
5
2 1 4 3 5
out: 3
*/
void update(int x, int val){
	while(x <= N){
		BIT[x] = max(BIT[x], val);
		x += (x & (-x));
	}
}

int get(int x){
	int res = 0;
	while(x > 0){
		res = max(res, BIT[x]);
		x -= (x & (-x));
	}
	return res;
}

bool cmp(ii a, ii b){
	return a.fi < b.fi;
}
bool cmp2(ii a, ii b){
	return a.se < b.se;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N;
	FOR(i, 1, N){
		cin >> a[i].first;
		F[i] = 1;
		a[i].second = i;
	}
	map<int, int> mp;
	sort(a + 1, a + N + 1, cmp);
	FOR(i, 1, N){
		if(mp[a[i].fi] == 0){
			int x = mp.size();
			mp[a[i].fi] = x;
			a[i].fi = x;
		}
		else a[i].fi = mp[a[i].fi];
	}
	sort(a + 1, a + N + 1, cmp2);
	int ans = 0;
	FOR(i, 1, N){
		int x = get(a[i].fi - 1);
		F[i] = x + 1;
		ans = max(ans, F[i]);
		update(a[i].fi, F[i]);
	}
	cout << ans << endl;
}
