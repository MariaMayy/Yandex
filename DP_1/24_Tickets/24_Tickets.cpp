#include <iostream>
#include <vector>

#define MAX_INT 2147483647

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> A(N + 3), B(N + 3), C(N + 3);
	vector<int> dp(N + 3);

	dp[0] = dp[1] = dp[2] = 0;
	A[0] = A[1] = A[2] = B[0] = B[1] = B[2] = C[0] = C[1] = C[2] = MAX_INT;

	for (int i = 3; i < N + 3; i++) {
		cin >> A[i] >> B[i] >> C[i];
	}

	for (int i = 3; i < N + 3; i++) {
		int k = min(dp[i - 1] + A[i], dp[i - 2] + B[i - 1]);
		dp[i] = min(k, dp[i - 3] + C[i - 2]);
	}

	cout << dp[N + 2];
	return 0;
}
