#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int iSize = max(N, 3);
    vector<int> dp(iSize);

    dp[0] = 2;
    dp[1] = 4;
    dp[2] = 7;

    for (int i = 3; i < N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    cout << dp[N - 1];

    return 0;
}
