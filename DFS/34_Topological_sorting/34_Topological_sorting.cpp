#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> result;
vector<int> colors;

bool dfs(const vector<vector<int>>& graph, int now) {
    colors[now] = 1; // the current vertex has been visited, but all the vertices 
    // reachable from it have not yet been visited
    for (int neig : graph[now]) {
        if (colors[neig] == 0) { // haven't visited yet
            if (dfs(graph, neig)) return true;
        }
        else if (colors[neig] == 1) return true;  
    }

    colors[now] = 2; // all vertices reachable from the current one have been visited
    result.push(now);
    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V + 1);
    colors.resize(V + 1);
    bool bOK = true;

    for (int i = 0; i < E; i++) {
        int iFirst, iSecond;
        cin >> iFirst >> iSecond;
        graph[iFirst].push_back(iSecond);
    }

    for (int i = 1; i < V + 1; i++) {
        if (colors[i] == 0) { // 0 - haven't visited yet
            if (dfs(graph, i)) {
                bOK = false; // impossible to construct a topological sorting
            }
        }
    }

    if (bOK) {
        while (!result.empty()) {
            cout << result.top() << " ";
            result.pop();
        }
    }
    else cout << -1;

    return 0;
}
