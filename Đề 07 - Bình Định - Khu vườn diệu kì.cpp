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
const int MAX = 3e6 + 5;

ll N, a[MAX], t;

deque<ll> dQmin, dQmax;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N >> t;
	FOR(i, 1, N) cin >> a[i];
	
	int i = 1, j = 1, ans = 0;
	dQmin.push_back(1); dQmax.push_back(1);
	while(j <= N){
		if(a[dQmax.front()] - a[dQmin.front()] <= t){
			ans = max(ans, j - i + 1);
			++j;
			while(!dQmin.empty() && a[j] <= a[dQmin.back()]) dQmin.pop_back();
			while(!dQmax.empty() && a[j] >= a[dQmax.back()]) dQmax.pop_back();
			dQmin.push_back(j);
			dQmax.push_back(j);
		}
		else{
			i++;
			if(dQmin.front() < i) dQmin.pop_front();
			if(dQmax.front() < i) dQmax.pop_front();
		}
	}
	cout << ans << endl;
}
