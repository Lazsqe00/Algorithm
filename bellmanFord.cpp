#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge{
    int x, y, w;
};

int n, m, s;
vector<edge> adj;
int d[1000];

void nhap(){
    cin >> n >> m >> s;
    adj.clear();
    for(int i = 0; i < m; i++){
        int x, y, w; 
        cin >> x >> y >> w;
        adj.push_back({x, y, w});
        adj.push_back({y, x, w}); 
    }
}

void bellmanFord(int s){
    for(int i = 1; i <= n; i++) d[i] = INT_MAX;
    d[s] = 0;

    for(int i = 1; i <= n-1; i++){
        for(edge e : adj){
            int x = e.x, y = e.y, w = e.w;
            if(d[y] != INT_MAX && d[x] > d[y] + w){
                d[x] = d[y] + w;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(d[i] == INT_MAX) cout << -1 << ' ';
        else cout << d[i] << ' ';
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        nhap();
        bellmanFord(s);
    }
}
