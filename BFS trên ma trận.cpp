char a[101][101];
bool visited[101][101]; 
int n, m;

struct Point {
	int x, y, value;
};

vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool isValid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m && !visited[i][j] && a[i][j] != '*';
}

int bfs(Point start, Point end) {
	visited[start.x][start.y] = true;
	queue<Point> q;
	q.push(start);
	while (!q.empty()) {
		Point u = q.front();
		q.pop();
		if (u.x == end.x && u.y == end.y) {
			return u.value;
		}
		for (auto v : direction) {
			int i1 = u.x + v.first;
			int j1 = u.y + v.second;
			if (isValid(i1, j1)) {
				visited[i1][j1] = true;
				q.push({i1, j1, u.value + 1});
			}
		}
	}
	return -1;
}
