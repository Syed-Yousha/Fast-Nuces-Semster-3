#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;

    Node() : data(0), next(NULL) {}
    Node(int d) : data(d), next(NULL) {}
};

class Graph 
{
private:
    bool** adj;
    int vertices;
    Node* AdjList;

public:
    Graph(int v) {
        this->vertices = v;
        adj = new bool*[vertices];
        for (int i = 0; i < vertices; i++) {
            adj[i] = new bool[vertices];
            for (int j = 0; j < vertices; j++) {
                adj[i][j] = false;
            }
        }

        AdjList = new Node[vertices];
    }

    void addEdge(int i, int j) 
	{
        adj[i][j] = true;
        adj[j][i] = true;
    }

    void printMat() {
        cout << "\nAdjacency Matrix: \n\n";
        cout << "\n   1 2 3 4 5\n";

        for (int i = 0; i < vertices; i++) {
            cout << endl
                 << i + 1 << "  ";
            for (int j = 0; j < vertices; j++) {
                cout << adj[i][j] << " ";
            }
        }
    }

    void _AdjList() 
	{
        for (int i = 0; i < vertices; i++) 
		{
            for (int j = 0; j < vertices; j++) 
			{
                if (adj[i][j]) 
				{
                    Node* temp = new Node(j);
                    temp->next = AdjList[i].next;
                    AdjList[i].next = temp;
                }
            }
        }
    }

    void printList() 
	{
        cout << "\n\nAdjacency List: \n\n";

        for (int i = 0; i < vertices; i++) 
		{
            cout << endl
                 << i + 1 << ": ";
            Node* temp = AdjList[i].next;
            while (temp != NULL) 
			{
                cout << temp->data + 1 << " ";
                temp = temp->next;
            }
        }
    }

    void BFS(int start) 
	{
        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; i++) 
		{
            visited[i] = false;
        }

        queue<int> q;
        visited[start] = true;
        q.push(start);

        cout << "\nBFS Traversal: ";

        while (!q.empty()) 
		{
            int current = q.front();
            q.pop();
            cout << current + 1 << " ";

            Node* temp = AdjList[current].next;
            while (temp != NULL) 
			{
                int adjNode = temp->data;
                if (!visited[adjNode]) 
				{
                    visited[adjNode] = true;
                    q.push(adjNode);
                }
                temp = temp->next;
            }
        }

        delete[] visited;
    }

    void DFSUtil(int start, bool* visited) 
	{
        visited[start] = true;
        cout << start + 1 << " ";

        Node* temp = AdjList[start].next;
        while (temp != NULL) 
		{
            int adjNode = temp->data;
            if (!visited[adjNode]) 
			{
                DFSUtil(adjNode, visited);
            }
            temp = temp->next;
        }
    }

    void DFS(int start) 
	{
        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; i++) 
		{
            visited[i] = false;
        }

        cout << "\nDFS Traversal: ";
        DFSUtil(start, visited);

        delete[] visited;
    }

    ~Graph() 
	{
        for (int i = 0; i < vertices; i++)
            delete[] adj[i];
        delete[] adj;
        delete[] AdjList;
    }
};

int main() 
{
    Graph obj(5);

    obj.addEdge(0, 3);
    obj.addEdge(3, 4);
    obj.addEdge(3, 1);
    obj.addEdge(1, 4);
    obj.addEdge(4, 2);

    obj.printMat();
    obj._AdjList();
    obj.printList();

    obj.BFS(0);
    obj.DFS(0);

    return 0;
}
