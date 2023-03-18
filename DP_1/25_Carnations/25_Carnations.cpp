#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> dp(N);
    vector<int> vCur(N);

    for (int i = 0; i < N; i++) {
        cin >> vCur[i];
    }

    sort(vCur.begin(), vCur.end());

    dp[1] = vCur[1] - vCur[0];
    dp[2] = vCur[2] - vCur[0];

    for (int i = 3; i < N; i++) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + vCur[i] - vCur[i - 1]; // 1. связали оптимально (i-2) гвоздика и связали i с i-1
        // 2. либо i-2 уже соединен с i-1, то есть (i-1) оптимально соединены и надо еще связать i с i-1
    }

    cout << dp[N - 1];
    return 0;
}
