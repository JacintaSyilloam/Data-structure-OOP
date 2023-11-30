#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max(); // Infinity

// Function to perform Dijkstra's algorithm
void dijkstra(const vector<vector<int>> &graph, int start)
{
    int n = graph.size(); // Number of vertices

    // Initialize distances and visited array
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);

    // Distance from the start node to itself is 0
    dist[start] = 0;

    for (int count = 0; count < n - 1; ++count)
    {
        // Find the vertex with the minimum distance value
        int u = -1; 
        for (int v = 0; v < n; ++v) // For each vertex
        {
            if (!visited[v] && (u == -1 || dist[v] < dist[u])) // If vertex v is not visited and dist[v] is less than dist[u]
            {
                u = v; // Set u to v
            }
        }

        // Mark the selected vertex as visited
        visited[u] = true;

        // Update the distance value of the adjacent vertices of the selected vertex
        for (int v = 0; v < n; ++v)
        {
            if (!visited[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) // If vertex v is not visited and there is an edge from u to v and total weight of path from start to v through u is smaller than current value of dist[v]
            {
                dist[v] = dist[u] + graph[u][v]; // Update dist[v]
            }
        }
    }

    // Print the result
    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "To node " << i << ": " << (dist[i] == INF ? "INF" : to_string(dist[i])) << endl;
    }
}

int main()
{
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 2, INF, 1, INF},
        {2, 0, 4, INF, INF},
        {INF, 4, 0, 5, 1},
        {1, INF, 5, 0, 3},
        {INF, INF, 1, 3, 0}};

    // Starting node
    int startNode = 0;

    // Perform Dijkstra's algorithm
    dijkstra(graph, startNode);

    return 0;
}
