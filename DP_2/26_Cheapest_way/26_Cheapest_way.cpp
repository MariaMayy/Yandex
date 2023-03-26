#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> cost(N, vector<int> (M));
    vector<vector<int>> dp(N, vector<int>(M, 999));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> cost[i][j];
        }
    }

    dp[0][0] = cost[0][0];
    for (int i = 1; i < N; i++) dp[i][0] = dp[i - 1][0] + cost[i][0];
    for (int j = 1; j < M; j++) dp[0][j] = dp[0][j - 1] + cost[0][j];

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + cost[i][j];
        }
    }

    cout << dp[N - 1][M - 1];

    return 0;
}

