#include <cstdio>
#include <cstring>

int r_len, c_len;
int field[500][500];
int dp[500][500];

int r_way[4] = { 0,0,1,-1 };
int c_way[4] = { 1,-1,0,0 };

int solve(int r_cur, int c_cur) {
	if (r_cur == r_len - 1 && c_cur == c_len - 1) return 1;
	int& ans = dp[r_cur][c_cur];
	if (ans != -1) return ans;
	ans = 0;

	for (int i = 0; i < 4; i++) {
		int r_next = r_cur + r_way[i];
		int c_next = c_cur + c_way[i];
		if (r_next < 0 || r_next >= r_len || c_next < 0 || c_next >= c_len) continue;
		if (field[r_cur][c_cur] > field[r_next][c_next]) {
			ans += solve(r_next, c_next);
		}
	}
	return ans;
}

int main() {
	scanf("%d %d", &r_len, &c_len);
	for (int r = 0; r < r_len; r++) {
		for (int c = 0; c < c_len; c++) {
			scanf("%d", &field[r][c]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", solve(0, 0));

	return 0;
}