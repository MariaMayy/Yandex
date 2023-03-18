#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> dp(N);
    dp[0] = 1; // in front of the board, from 0 to 1 one option

    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            if (i - j < 0) break;
            dp[i] += dp[i - j];
        }
    }

    cout << dp[N - 1];

    return 0;
}

