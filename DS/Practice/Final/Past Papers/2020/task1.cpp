#include <iostream>

const int MAX_VERTICES = 100;  // Adjust this based on your needs
const int INF = 1e9;           // Use a large value as infinity

class Graph {
public:
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

    Graph(int v) : vertices(v) {
        for (int i = 0; i < MAX_VERTICES; ++i) {
            for (int j = 0; j < MAX_VERTICES; ++j) {
                adjacencyMatrix[i][j] = (i == j) ? 0 : INF;
            }
        }
    }

    void addEdge(int u, int v, int weight) {
        adjacencyMatrix[u][v] = weight;
        adjacencyMatrix[v][u] = weight;  // For undirected graph
    }

    void dijkstra(int start) {
        int distance[MAX_VERTICES];
        bool visited[MAX_VERTICES] = {false};

        for (int i = 0; i < vertices; ++i) {
            distance[i] = INF;
        }

        distance[start] = 0;

        for (int i = 0; i < vertices - 1; ++i) {
            int u = minDistance(distance, visited);
            visited[u] = true;

            for (int v = 0; v < vertices; ++v) {
                if (!visited[v] && adjacencyMatrix[u][v] != INF && distance[u] + adjacencyMatrix[u][v] < distance[v]) {
                    distance[v] = distance[u] + adjacencyMatrix[u][v];
                }
            }
        }

        std::cout << "Shortest distances from node " << start << ":\n";
        for (int i = 0; i < vertices; ++i) {
            std::cout << "To node " << i << ": " << distance[i] << std::endl;
        }
    }

private:
    int minDistance(const int distance[], const bool visited[]) {
        int minDist = INF, minIndex = -1;

        for (int i = 0; i < vertices; ++i) {
            if (!visited[i] && distance[i] < minDist) {
                minDist = distance[i];
                minIndex = i;
            }
        }

//		std::cout<<minDist<<std::endl;
        return minIndex;
    }
};

int main() {
    // Example usage
    int vertices = 6;
    Graph graph(vertices);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 7);
    graph.addEdge(2, 4, 3);
    graph.addEdge(3, 4, 1);
    graph.addEdge(3, 5, 5);
    graph.addEdge(4, 5, 2);

    int startNode = 0;
    graph.dijkstra(startNode);

    return 0;
}

