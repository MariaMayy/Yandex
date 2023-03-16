#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N;
    stack<pair<int, int>> st;
    vector<pair<int, int>> vPair;

    cin >> N;
    vector<int> vRes(N, -1);

    for (int i = 0; i < N; i++) {
        int iNum;
        cin >> iNum;
        vPair.push_back(make_pair(iNum, i));
    }

    st.push(vPair[0]);

    for (int i = 1; i < vPair.size(); i++) {
        while (!st.empty() && (st.top().first > vPair[i].first)) {
            vRes[st.top().second] = i;
            st.pop();
        }
        st.push(vPair[i]);
    }

    for (auto elem : vRes) cout << elem << " ";

    return 0;
}

