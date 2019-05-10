#include <cstdio>
#include <tuple>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

char maze[1000][1000];
int dist[1000][1000][11][2]; // 0 : day, 1 : night
int r_len, c_len, k_num;

const int r_way[4] = { 0,0,1,-1 };
const int c_way[4] = { 1,-1,0,0 };

int bfs_solve() {
	queue<tuple<int, int, int, int>> q;
	q.push(make_tuple(0, 0, 0, 0)); // day or night (0 : day, 1 : night), broken wall, row, col
	memset(dist, -1, sizeof(dist));
	dist[0][0][0][0] = 1;

	while (!q.empty()) {
		int d_or_n, broken, r_cur, c_cur;
		tie(d_or_n, broken, r_cur, c_cur) = q.front();
		q.pop();
		if (r_cur == r_len -1 && c_cur == c_len -1) {
			return dist[r_cur][c_cur][broken][d_or_n];
		}
		for (int i = 0; i < 4; i++) {
			int r_next = r_cur + r_way[i];
			int c_next = c_cur + c_way[i];
			if (r_next < 0 || r_next >= r_len || c_next < 0 || c_next >= c_len) continue;
			if (maze[r_next][c_next] == '0') {
				if (dist[r_next][c_next][broken][1 - d_or_n] == -1) {
					dist[r_next][c_next][broken][1 - d_or_n] = dist[r_cur][c_cur][broken][d_or_n] + 1;
					q.push(make_tuple(1 - d_or_n, broken, r_next, c_next));
				}
			}
			else if (d_or_n == 0) {
				if (broken < k_num && dist[r_next][c_next][broken + 1][1 - d_or_n] == -1) {
					dist[r_next][c_next][broken + 1][1 - d_or_n] = dist[r_cur][c_cur][broken][d_or_n] + 1;
					q.push(make_tuple(1 - d_or_n, broken + 1, r_next, c_next));
				}
			}
			else if (dist[r_cur][c_cur][broken][1 - d_or_n] == -1) {
				dist[r_cur][c_cur][broken][1 - d_or_n] = dist[r_cur][c_cur][broken][d_or_n] + 1;
				q.push(make_tuple(1 - d_or_n, broken, r_cur, c_cur));
			}
		}
	}

	return -1;
}


int main() {
	char input[1004];
	scanf("%d %d %d",&r_len,&c_len,&k_num);
	for (int r = 0; r < r_len;r++) {
		scanf("%s",input);
		for (int c = 0; c < c_len;c++) {
			maze[r][c] = input[c];
		}
	}
	printf("%d\n",bfs_solve());

	return 0;
}