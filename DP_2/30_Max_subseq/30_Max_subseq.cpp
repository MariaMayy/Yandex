#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N;
    vector<int> vFirtst(N);

    for (int i = 0; i < N; i++) {
        cin >> vFirtst[i];
    }

    cin >> M;
    vector<int> vSecond(M);
    for (int i = 0; i < M; i++) {
        cin >> vSecond[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(M + 1));
    vector<int> vRes;

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < M + 1; j++) {
            if (vFirtst[i - 1] == vSecond[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // restoring the answer from the end
    int i = N, j = M;

    while (i > 0 && j > 0) {
        if (vFirtst[i - 1] == vSecond[j - 1]) {
            vRes.push_back(vFirtst[i - 1]);
            i--;
            j--;
        } 
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    for (int k = vRes.size() - 1; k >= 0; k--) {
        cout << vRes[k] << ' ';
    }

    return 0;
}
