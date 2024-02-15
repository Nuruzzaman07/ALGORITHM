#include <iostream>

#include <vector>

#include <climits>

using namespace std;

const int INF = INT_MAX; // Infinity value for unreachable nodes

void floydWarshall(vector<vector<int>> &graph, int V) {

    // Initialize the distance matrix

    vector<vector<int>> dist(V, vector<int>(V, 0));

    // Copy the input graph to the distance matrix

    for (int i = 0; i < V; i++) {

        for (int j = 0; j < V; j++) {

            dist[i][j] = graph[i][j];

        }

    }

    // Compute shortest paths

    for (int k = 0; k < V; k++) {

        for (int i = 0; i < V; i++) {

            for (int j = 0; j < V; j++) {

                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];

                }

            }

        }

    }

    // Print the result

    cout << "Shortest distances between every pair of vertices:\n";

    for (int i = 0; i < V; i++) {

        for (int j = 0; j < V; j++) {

            if (dist[i][j] == INF) {

                cout << "INF\t";

            } else {

                cout << dist[i][j] << "\t";

            }

        }

        cout << endl;

    }

}

int main() {

    // Number of vertices in the graph

    int V;

    cout << "Enter the number of vertices: ";

    cin >> V;

    // Input the graph as an adjacency matrix

    cout << "Enter the adjacency matrix for the graph (use INF for infinity):\n";

    vector<vector<int>> graph(V, vector<int>(V));

    for (int i = 0; i < V; i++) {

        for (int j = 0; j < V; j++) {

            cin >> graph[i][j];

        }

    }

    // Run the algorithm

    floydWarshall(graph, V);

    return 0;

}

