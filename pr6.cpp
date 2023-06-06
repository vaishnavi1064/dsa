#include<iostream>
using namespace std;

const int MAX = 10;
int cost[MAX][MAX], n;
int qu[MAX], front, rear, visit[MAX], visited[MAX];
int stk[MAX], top, visit1[MAX], visited1[MAX];

void bfs(int start) {
    cout << "BFS Traversal: ";
    cout << start << " ";
    visited[start] = 1;
    qu[rear++] = start;

    while (front < rear) {
        int v = qu[front++];
        for (int j = 1; j <= n; j++) {
            if (cost[v][j] != 0 && visited[j] != 1 && visit[j] != 1) {
                visit[j] = 1;
                qu[rear++] = j;
                cout << j << " ";
            }
        }
        visit[v] = 0;
        visited[v] = 1;
    }
    cout << endl;
}

void dfs(int start) {
    cout << "DFS Traversal: ";
    cout << start << " ";
    visited1[start] = 1;
    stk[++top] = start;

    while (top != 0) {
        int v = stk[top];
        top--;

        for (int j = n; j >= 1; j--) {
            if (cost[v][j] != 0 && visited1[j] != 1 && visit1[j] != 1) {
                visit1[j] = 1;
                stk[++top] = j;
                cout << j << " ";
                break;
            }
        }
        visit1[v] = 0;
        visited1[v] = 1;
    }
    cout << endl;
}

int main() {
    int m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter the edges (u v):" << endl;
    for (int k = 1; k <= m; k++) {
        int i, j;
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1;
    }

    // Display adjacency matrix
    cout << "The adjacency matrix of the graph is:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }

    int start;
    cout << "Enter the initial vertex for BFS: ";
    cin >> start;
    bfs(start);

    cout << "Enter the initial vertex for DFS: ";
    cin >> start;
    dfs(start);

    return 0;
}
