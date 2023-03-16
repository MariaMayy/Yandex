#include <iostream>
#include <stack>

using namespace std;

int main() {
    int N, iCur = 0;
    stack<int> st;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int iNum;
        cin >> iNum;
        st.push(iNum);

        while (!st.empty() && st.top() - iCur == 1) {
            st.pop();
            iCur++;
        } 
    }

    if (iCur == N) cout << "YES";
    else cout << "NO";

    return 0;
}
