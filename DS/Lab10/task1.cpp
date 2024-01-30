#include <iostream>
using namespace std;

//BST
class Node
{
	public:
	int data;
	Node *right;
	Node *left;
	
	Node()
	{
		right = NULL;
		left = NULL;
	}

};

class BST
{
	public:
	Node *root;
	BST():root(NULL)
	{}
	
	
	
	void insert_node(int data)
	{
		Node *new_node = new Node;
		new_node->data = data;
		
		Node *tmp = new Node;
		if(root == NULL)
		{
			root = new_node;
			cout<<"\nNode inserted";
			return;
		}
		else
		{
			tmp = root;
		}
		
		
		while(tmp != NULL)
		{
			
			if(tmp->data == new_node->data)
			{
				return;
			}
			
			//left
			if((new_node->data < tmp->data) && (tmp->left == NULL))
			{
				tmp->left = new_node;
				cout<<"\nNode inserted";
				return;
			}
			else if(new_node->data < tmp->data)
			{
				tmp = tmp->left;
			}
			
			//right
			if((new_node->data > tmp->data) && (tmp->right == NULL))
			{
				tmp->right = new_node;
				cout<<"\nNode inserted";
				return;
			}
			else if(data > tmp->data)
			{
				tmp = tmp->right;
			}	
		}
		
		return;
	}	
	
	void display() {
        displayInOrder(root);
    }

    void displayInOrder(Node* node) {
        if (node != NULL) {
            displayInOrder(node->left);
            cout<< " " << node->data << " ";
            displayInOrder(node->right);
        }
    }
	
};

int main()
{
	BST obj;
	obj.insert_node(2000);
	obj.insert_node(230);
	obj.insert_node(120);
	obj.insert_node(150);
	obj.insert_node(4000);
	obj.insert_node(450);
	obj.insert_node(405);
	obj.insert_node(100);
	
	cout<<endl<<"\nPakages Prices: "<<endl;
	obj.display();
	
	return 0;
}
