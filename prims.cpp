#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, weight;
};

vector<Edge> primMST(vector<vector<Edge>>& graph, int start) {
    int V = graph.size();
    vector<bool> inMST(V, false);
    vector<Edge> MST;
    priority_queue<pair<int, int>> pq;

    pq.push({0, start});

    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) {
            continue;
        }

        inMST[u] = true;

        if (weight != 0) {
            MST.push_back({u, weight});
        }

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;

            if (!inMST[v]) {
                pq.push({w, v});
            }
        }
    }

    return MST;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<Edge>> graph(V);

    cout << "Enter the edges and their weights:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    vector<Edge> minimumSpanningTree = primMST(graph, start);

    cout << "Minimum Spanning Tree Edges:" << endl;
    for (const Edge& edge : minimumSpanningTree) {
        cout << edge.to << " - " << edge.weight << endl;
    }

    return 0;
}
