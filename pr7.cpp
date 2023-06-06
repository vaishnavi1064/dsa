#include <iostream>
#include <vector>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int destination;
    int cost;
};

// Function to add an edge to the graph
void addEdge(vector<vector<Edge>>& graph, int source, int destination, int cost) {
    Edge edge;
    edge.destination = destination;
    edge.cost = cost;
    graph[source].push_back(edge);
}

// Function to perform Depth First Search (DFS) traversal
void dfs(vector<vector<Edge>>& graph, vector<bool>& visited, int vertex) {
    visited[vertex] = true;

    for (const Edge& edge : graph[vertex]) {
        if (!visited[edge.destination]) {
            dfs(graph, visited, edge.destination);
        }
    }
}

// Function to check if the graph is connected
bool isConnected(vector<vector<Edge>>& graph, int numNodes) {
    vector<bool> visited(numNodes, false);
    dfs(graph, visited, 0);

    // Check if all nodes are visited
    for (bool nodeVisited : visited) {
        if (!nodeVisited) {
            return false;
        }
    }

    return true;
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<Edge>> graph(numNodes);

    cout << "Enter the edges in the format: source destination cost\n";
    for (int i = 0; i < numEdges; ++i) {
        int source, destination, cost;
        cin >> source >> destination >> cost;
        addEdge(graph, source, destination, cost);
    }

    bool connected = isConnected(graph, numNodes);
    if (connected) {
        cout << "The graph is connected.\n";
    } else {
        cout << "The graph is not connected.\n";
    }

    return 0;
}
