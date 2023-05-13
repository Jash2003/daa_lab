#include <iostream>
#include <algorithm>
using namespace std;
#define V 5

struct Edge {
    int src, dest, weight;
};

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(int parent[], int i) {
    if (parent[i] == i) {
        return i;
    }
    return find(parent, parent[i]);
}

void unionSet(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

void kruskalMST(int graph[V][V]) {
    Edge edges[V*V];
    int edgeCount = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j]) {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }
    sort(edges, edges+edgeCount, cmp);
    int parent[V], rank[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    
    int mstWeight = 0;
    cout << "Edge \tWeight\n";
    for (int i = 0; i < edgeCount; i++) {
        int x = edges[i].src;
        int y = edges[i].dest;
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        if (rootX != rootY) {
            cout << x << " - " << y << "\t" << edges[i].weight << endl;
            mstWeight += edges[i].weight;
            unionSet(parent, rank, rootX, rootY);
        }
    }
    cout << "Minimum Cost Spanning Tree Weight: " << mstWeight << endl;
}
int main() {
    int graph[V][V];
    cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    kruskalMST(graph);
    return 0;
}
