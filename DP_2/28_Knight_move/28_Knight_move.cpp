#include <iostream>
#include<vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> dp(N + 2, vector<int>(M + 2)); // count

	dp[2][2] = 1; // start
	for (int i = 2; i < N + 2; i++) {
		for (int j = 2; j < M + 2; j++) {
			if (i == 2 && j == 2) continue;
			dp[i][j] = dp[i - 1][j - 2] + dp[i - 2][j - 1]; // left, upper
		}
	}

	cout << dp[N + 1][M + 1];
	return 0;
}
