#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
    int vertices; // number of vertices
    vector<vector<int>> adjList; // adjacency list

    Graph(int v) : vertices(v), adjList(v) {} // constructor

    void addEdge(int v, int w) { // add edge between vertices v and w
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }

    void BFS(int start) { // breadth-first search
        vector<bool> visited(vertices, false); // initialize visited array
        queue<int> bfsQueue; // initialize queue

        visited[start] = true; // mark start vertex as visited
        bfsQueue.push(start); // push start vertex to queue

        cout << "Breadth-First Search starting from node " << start << ": ";

        while (!bfsQueue.empty()) { // while queue is not empty
            int currentVertex = bfsQueue.front(); // get front of queue
            bfsQueue.pop(); // pop front of queue
            cout << currentVertex << " "; // print current vertex

            for (const auto& neighbor : adjList[currentVertex]) { // for each neighbor of current vertex
                if (!visited[neighbor]) { // if neighbor is not visited
                    visited[neighbor] = true;
                    bfsQueue.push(neighbor);
                }
            }
        }

        cout << endl;
    }

    // print graph adjacency list
    void printGraph() {
        cout << "Graph Adjacency List:\n";
        for (int i = 0; i < vertices; ++i) {
            cout << i << ": ";
            for (const auto& neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    g.addEdge(4, 5);
    g.addEdge(5, 7);

    g.printGraph(); // print graph adjacency list

    g.BFS(0); // perform BFS starting from vertex 0

    return 0;
}