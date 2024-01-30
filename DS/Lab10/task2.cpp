#include <iostream>
using namespace std;

class AVLNode 
{
public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int value) : data(value), left(NULL), right(NULL), height(1) {}
};

class AVLTree 
{
private:
    AVLNode* root;

    int height(AVLNode* node) 
	{
        if (node == NULL) return 0;
        return node->height;
    }

    int getBalance(AVLNode* node) 
	{
        if (node == NULL) return 0;
        return height(node->left) - height(node->right);
    }

    void updateHeight(AVLNode* node) 
	{
        if (node != NULL) {
            node->height = 1 + max(height(node->left), height(node->right));
        }
    }

    AVLNode* rightRotate(AVLNode* y) 
	{
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    AVLNode* leftRotate(AVLNode* x)
	 {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    AVLNode* insert(AVLNode* node, int value)
	 {
        if (node == NULL) {
            return new AVLNode(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            return node;
        }

        updateHeight(node);

        int balance = getBalance(node);

        if (balance > 1 && value < node->left->data) 
		{
            return rightRotate(node);
        }

        if (balance < -1 && value > node->right->data) 
		{
            return leftRotate(node);
        }

        if (balance > 1 && value > node->left->data) 
		{
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && value < node->right->data) 
		{
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorderTraversal(AVLNode* root) 
	{
        if (root != NULL) {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

public:
    AVLTree() : root(NULL) {}

    void insert(int value) 
	{
        root = insert(root, value);
    }

    void leftRotateRoot() {
        if (root != NULL && root->right != NULL) 
		{
            root = leftRotate(root);
        }
    }

    void displayTree() 
	{
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    AVLTree avlTree;

    avlTree.insert(50);
    avlTree.insert(30);
    avlTree.insert(70);
    avlTree.insert(20);
    avlTree.insert(40);
    avlTree.insert(60);
    avlTree.insert(80);

    cout << "AVL Tree before left rotation: ";
    avlTree.displayTree();

    avlTree.insert(55);
    avlTree.leftRotateRoot();

    cout << "AVL Tree after left rotation: ";
    avlTree.displayTree();

    return 0;
}

