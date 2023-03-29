#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int now) {
    visited[now] = true;
    for (int neig : graph[now]) {
        if (!visited[neig]) { // didn't visit a neighbor
           dfs(graph, visited, neig);
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V + 1);
    vector<bool> visited(V + 1);
    // initialization
    for (int i = 0; i < V + 1; i++) {
        visited[i] = false;
    }
   
    for (int i = 0; i < E; i++) {
        int iFirst, iSecond;
        cin >> iFirst >> iSecond;
        graph[iFirst].push_back(iSecond);
        graph[iSecond].push_back(iFirst);
    }

    dfs(graph, visited, 1);

    int iCount = 0;
    for (int i = 0; i < V + 1; i++) {
        if (visited[i] == true) iCount++;
    }
    cout << iCount << endl;

    for (int i = 1; i < V + 1; i++) {
        if (visited[i]) cout << i << " ";
    }

    return 0;
}

