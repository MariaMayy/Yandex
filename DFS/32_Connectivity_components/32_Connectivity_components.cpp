#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int now, int comp, vector<set<int>>& components) {
    visited[now] = true;
    components.resize(comp + 1);
    components[comp].insert(now);
    for (int neig : graph[now]) {
        if (!visited[neig]) {
            components[comp].insert(neig);
            dfs(graph, visited, neig, comp, components);
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V + 1);
    vector<bool> visited(V + 1, false);

    // fill graph
    for (int i = 0; i < E; i++) {
        int iFirst, iSecond;
        cin >> iFirst >> iSecond;
        graph[iFirst].push_back(iSecond);
        graph[iSecond].push_back(iFirst);
    }
    // count of components, cycle by vertex
    int comp = 0;
    vector<set<int>> components(comp);
    for (int i = 1; i < V + 1; i++) {
        if (!visited[i]) {
            dfs(graph, visited, i, comp, components);
            comp++;
        }
    }
    
    cout << comp << endl;

    // components
    for (int i = 0; i < comp; i++) {
        cout << components[i].size() << endl;
        for (int cur : components[i]) {
            cout << cur << " ";
        }
        cout << endl;
    }


    return 0;
}

