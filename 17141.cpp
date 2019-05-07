#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int n, m, possible;
int lab[50][50];
int dist[50][50];
vector<pair<int, int>> virus_pos, cur_pos;
vector<bool> start_virus;
int ans = -1;
int all_case = 0;

const int r_way[4] = { 0,0,1,-1 };
const int c_way[4] = { 1,-1,0,0 };

int bfs(queue<pair<int, int>> &q) {
	while (!q.empty()) {
		int r_cur = q.front().first;
		int c_cur = q.front().second;
		q.pop();
		for (int i = 0; i < 4;i++) {
			int r_next = r_cur + r_way[i];
			int c_next = c_cur + c_way[i];
			if (r_next < 0 || r_next >= n || c_next < 0 || c_next >= n) continue;
			if (lab[r_next][c_next] != 1 && dist[r_next][c_next] == -1) {
				dist[r_next][c_next] = dist[r_cur][c_cur] + 1;
				q.push({ r_next,c_next });
			}
		}
	}
	int max_time = -1;
	bool all_flag = true;
	for (int r = 0; r < n;r++) {
		for (int c = 0; c < n;c++) {
			if (lab[r][c] != 1 && dist[r][c] == -1) {
				all_flag = false; break;
			}
			if (max_time == -1 || max_time < dist[r][c]) max_time = dist[r][c];
		}
	}
	if (!all_flag) return -1;
	else return max_time;
}

void solve(int v_cur) {
	if (v_cur == m) {
		all_case += 1;
		memset(dist, -1, sizeof(dist));
		queue<pair<int, int>> q;
		for (int r = 0; r < v_cur;r++) {
			q.push({ cur_pos[r].first,cur_pos[r].second });
			dist[cur_pos[r].first][cur_pos[r].second] = 0;
		}
		int cur_ans = bfs(q);
		if (cur_ans == -1) return;
		if (ans == -1 || ans > cur_ans) {
			ans = cur_ans; return;
		}
	}
	int start_pos = -1;
	for (int r = possible - 1; r >= 0;r--) {
		if (start_virus[r]) {
			start_pos = r; break;
		}
	}
	for (int r = start_pos + 1; r < possible;r++) {
		start_virus[r] = true; cur_pos.push_back(virus_pos[r]);
		solve(v_cur + 1);
		start_virus[r] = false; cur_pos.pop_back();
	}
}

int main() {
	scanf("%d %d",&n,&m);
	for (int r = 0; r < n;r++) {
		for (int c = 0; c < n;c++) {
			int state;
			scanf("%d",&state);
			if (state == 2) {
				lab[r][c] = 0;
				virus_pos.push_back({r,c});
			}
			else {
				lab[r][c] = state;
			}
		}
	}
	possible = virus_pos.size();
	start_virus.resize(possible, false);
	solve(0);
	printf("%d\n",ans);

	return 0;
}