#include <iostream>
#include <cstring>
#define MOD 1000000007

using namespace std;

int dp[51];

int solve(int n) {
	if (n < 2) return 1;
	int& ans = dp[n];
	if (ans != -1) return ans;
	ans = 1;
	return ans += (solve(n - 1) + solve(n - 2)) % MOD;
}

int main() {
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << solve(n) << '\n';

	return 0;
}