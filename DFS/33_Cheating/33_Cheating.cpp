#include <iostream>
#include <vector>

using namespace std;
// false - can't be painted, true - can be painted
bool dfs(const vector<vector<int>>& graph, vector<int>& visited, int now, int color) {
    visited[now] = color;
    for (int neig : graph[now]) {
        if (visited[neig] == -1) { // haven't visited yet
            dfs(graph, visited, neig, 3 - color);
        } // visited, check the color of the current vertex and its neighbor
        else if (visited[neig] == color) return false;
    }
    return true;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V + 1);
    vector<int> visited(V + 1, -1);
    int color = 1;
    bool bOK = true; /// can be painted
    // fill
    for (int i = 0; i < E; i++) {
        int iFirst, iSecond;
        cin >> iFirst >> iSecond;
        graph[iFirst].push_back(iSecond);
        graph[iSecond].push_back(iFirst);
    }

    for (int i = 1; i < V + 1; i++) {
        if (visited[i] == -1) { // haven't visited yet
            if (!dfs(graph, visited, i, color)) {
                bOK = false;
                break;
            }
            color = 3 - color; // change color, painting in two colors
        }
    }

    if (bOK) cout << "YES";
    else cout << "NO";

    return 0;
}