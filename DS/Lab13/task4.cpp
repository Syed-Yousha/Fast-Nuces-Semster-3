#include <iostream>
#include <vector>

#define NUM_NODES 6

using namespace std;

const int INF = 1e9;  

int graph[NUM_NODES][NUM_NODES] = {
    {0, 3, 4, 0, 0, 0},
    {3, 0, 2, 3, 6, 0},
    {4, 2, 0, 1, 0, 0},
    {0, 3, 1, 0, 4, 2},
    {0, 6, 0, 4, 0, 1},
    {0, 0, 0, 2, 1, 0}
};

int min_distance(vector<int>& dist, vector<bool>& spt_set) {
    int min = INF, min_index;

    for (int v = 0; v < NUM_NODES; ++v) {
        if (!spt_set[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int src, int dest) {
    vector<int> dist(NUM_NODES, INF);
    vector<bool> spt_set(NUM_NODES, false);

    dist[src] = 0;

    for (int count = 0; count < NUM_NODES - 1; ++count) {
        int u = min_distance(dist, spt_set);
        spt_set[u] = true;

        for (int v = 0; v < NUM_NODES; ++v) {
            if (!spt_set[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest path from Node " << src + 1 << " to Node " << dest + 1 << ": ";
    int node = dest;
    while (node != src) {
        cout << node + 1 << " <- ";
        node = dist[node];  
    }
    cout << src + 1 << endl;

    cout << "Total weight of the path: " << dist[dest] << endl;
}

int main() {
    int source = 0;  
    int destination = 5;  

    dijkstra(source, destination);

    return 0;
}
