#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define M 10

class Node
{
	public:
		int data;
		Node *next = NULL;
};


class AdjList
{
	public:
	Node *adjlist[M];
	
	
	AdjList()
	{
		for(int i=0; i< M; i++)
		{
			adjlist[i] = NULL;
		}
	}	
	
	
	void add_edge(int src, int dest)
	{
		Node *newNode = new Node;
		newNode->data = dest;
		newNode->next = NULL;
		newNode->next = adjlist[src];
		adjlist[src] = newNode;
		
		
		//Undirected 
		newNode = new Node;
		newNode->data = src;
		newNode->next = NULL;
		newNode->next = adjlist[dest];
		adjlist[dest] = newNode;
	
	}
	
	
	void printList()
	{
		cout<<"\nAdjacency List:\n";
	
		for(int i=0; i<M; i++)
		{
			Node *temp = new Node;
			temp = adjlist[i];
			cout<< endl << i <<" : ";
			while(temp != NULL)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			
		}
		
	}
	
	
	void dfs(int startNode)
	{
		cout<<"\n\nDFS Traversal:\n";
		bool visited[M] = {0};
		stack<int> stk;
		
		stk.push(startNode);
		
		while(!stk.empty())
		{
			int curr = stk.top();
			stk.pop();
			
			if(!visited[curr])
			{
				cout<<curr<<" ";
				visited[curr] = 1;
			}
			
			
			Node *curr_ptr = adjlist[curr];
			while(curr_ptr != NULL)
			{
				
				if(!visited[curr_ptr->data])
				{
					stk.push(curr_ptr->data);
				}
				
				curr_ptr = curr_ptr->next;
			}
			
		}
		
		
	}
	
	
	void bfs(int startNode)
	{
		cout<<"\n\nBFS Traversersal:\n";
		bool visited[M] = {0};	
		queue<int> bfsq;
		
		
		visited[startNode] = 1;
		bfsq.push(startNode);
		
		
		while(!bfsq.empty())
		{
			int curr = bfsq.front();
			bfsq.pop();
			
			cout<<curr<<" ";
			Node *curr_val = adjlist[curr];
			
			while(curr_val != NULL)
			{
				if(!visited[curr_val->data])
				{
					visited[curr_val->data] = 1;
					bfsq.push(curr_val->data);
				}
				
				curr_val = curr_val->next;
			}
			
		}
		
	}
};



class AdjMat
{
	public:
	bool adjMat[M][M];
	int verts;
	
	
	AdjMat(int n): verts(n)
	{
		for(int i=0; i<M; i++)
		{
			for(int j=0; j<M; j++)
			{
				adjMat[i][j] = 0;
			}
		}
	}
	
	
	void add_edge(int src, int dest)
	{
		adjMat[src][dest] = 1;
		adjMat[dest][src] = 1;
	}
	
	
	void printMat()
	{
		
		cout<<"\n\nAdjacency Matrix: \n\n";
		
		
		cout<<" ";
		for(int i=0; i<verts; i++)
		{
			cout<<" "<<i;
		}
		
		for(int i=0; i<verts; i++)
		{
			cout<<endl<<i<<" ";
			for(int j=0; j<verts; j++)
			{
				cout<<adjMat[i][j]<<" ";
			}
		}
	}
};



int main()
{
	AdjList obj;
	
	obj.add_edge(1, 4);
	obj.add_edge(4, 2);
	obj.add_edge(4, 5);
	obj.add_edge(2, 5);
	obj.add_edge(5, 3);
	
	obj.printList();
	obj.dfs(1);
	obj.bfs(1);
	
	AdjMat obj2(6);
	obj2.add_edge(1, 4);
	obj2.add_edge(4, 2);
	obj2.add_edge(4, 5);
	obj2.add_edge(2, 5);
	obj2.add_edge(5, 3);
	
	
	obj2.printMat();
	return 0;
}
