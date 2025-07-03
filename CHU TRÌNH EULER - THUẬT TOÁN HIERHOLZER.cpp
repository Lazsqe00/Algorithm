// thuat toan Hierholzer dung stack tim chu trinh euler / duong di euler
set<int> adj[MAX];
void euler(int start){
	stack<int> st;
	vector<int> res; // luu ket qua duong di
	st.push(start);
	
	while(!st.empty()){
		int u = st.top();
		if(!adj[u].empty()){  // adj[u].size != 0
			int v = *adj[u].begin(); // lay dinh ke v dau tien cua u
			st.push(v);
			
			// xoa canh u, v
			adj[u].erase(v);
			adj[v].erase(u);
		}
		else{
			res.push_back(u);
			st.pop();
		}
	}
	for(auto x : res) cout << x << " ";
	cout << endl;
}
