#include <iostream>
#include <climits>
using namespace std;
#define V 3
int findMinKey(int key[], bool mstSet[]) {
    int minKey = INT_MAX, minIndex;
    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && key[i] < minKey) {
            minKey = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void primMST(int graph[V][V]) {
    int parent[V], key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int u = findMinKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[parent[i]][i] << endl;
    }
}

int main() {
    int graph[V][V];
    cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    primMST(graph);
    return 0;
}
