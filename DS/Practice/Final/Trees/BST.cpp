#include <iostream>
using anmesapce std;

class Node
{
	public:
	int key;
	Node *left;
	Node *right;
//	Node(): left(NULL), right(NULL){}
};

class BST
{
	Node *root;
	public:
		
	BST():root(NULL){}	
	
	Node* insertNode(Node *root, int key)
	{
		if(root == NULL)
		{
			Node *temp =  new Node;
			temp->key = key;
			temp->left = NULL;
			temp->right = NULL;
			return temp;
		}
		
		if(root->key > key)
		{
			root->left = insertNode(root->left, key);
		}
		else if(root->key < key)
		{
			root->right = insertNode(root->right, key);
		}
		
		return root;
	}
	
	Node* finding_minimum(Node* root)
	{
		Node* current=root;
		while(current && current->left!=NULL)
			current=current->left;
		
		return current;
	}
	
	Node* deleteNode(Node *root, int key)
	{
		if(root = NULL)
		{
			return root;
		}	
		
		if(key > root->key)
		{
			root->right = deleteNode(root->right, key);
		}
		else if(key < root->key)
		{
			root->left = deleteNode(root->left, key);
		}
		
		else{
			if(root->left = NULL)
			{
				Node *temp = root->right;
				delete root;
				return temp; 
			}	
			else if(root->right = NULL)
			{
				Node *temp = root->left;
				delete root;
				return temp; 
			}
			
			Node *temp = finding_minimum(root->root);
			root->key = temp->key;
			root->right=delete_node(root->right,temp->data);
		}
		
		
		return root;
	}
	
	
};
int main()
{
	
}
