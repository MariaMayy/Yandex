#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> cost(N, vector<int>(M));
    vector<vector<int>> dp(N, vector<int>(M, 0));
    vector<vector<string>> way(N, vector<string>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> cost[i][j];
        }
    }

    dp[0][0] = cost[0][0];
    // заполняем 0-й столбец 
    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i - 1][0] + cost[i][0];
        way[i][0] = way[i - 1][0] + "D ";
    }
    // заполняем 0-ю строку 
    for (int j = 1; j < M; j++) {
        dp[0][j] = dp[0][j - 1] + cost[0][j];
        way[0][j] = way[0][j - 1] + "R ";
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j] + cost[i][j];
                way[i][j] = way[i - 1][j] + "D ";
            }
            else {
                dp[i][j] = dp[i][j - 1] + cost[i][j];
                way[i][j] = way[i][j - 1] + "R ";
            }
        }
    }

    cout << dp[N - 1][M - 1] << endl;
    cout << way[N - 1][M - 1];

    return 0;
}

