#include <iostream>
#include <vector>
using namespace std;

void dijkstra(const vector<vector<int>>& adjMatrix, int start)
{
    int n = adjMatrix.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INT_MAX, minIndex;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] <= min) {
                min = dist[i];
                minIndex = i;
            }
        }

        int u = minIndex;
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && adjMatrix[u][v] && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v])
                dist[v] = dist[u] + adjMatrix[u][v];
        }
    }

    cout << "Minimum distances from City " << start << " ->\n";
    for (int i = 0; i < n; i++) {
        if (i != start) {
            cout << "City " << i << ": " << dist[i] << endl;
        }
    }
}

int main()
{
    vector<vector<int>> adjMatrix = {
            {0, 10, 0, 0, 15, 5},
            {10, 0, 10, 30, 0, 0},
            {0, 10, 0, 12, 5, 0},
            {0, 30, 12, 0, 0, 20},
            {15, 0, 5, 0, 0, 0},
            {5, 0, 0, 20, 0, 0}
    };
    dijkstra(adjMatrix, 0);

    return 0;
}
