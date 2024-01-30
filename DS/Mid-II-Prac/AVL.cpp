#include <iostream>
using namespace std;

class Node
{
    public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int key): key(key), height(1), left(NULL), right(NULL){}
};

class AVLTree
{
public:
    Node * root;

    int height(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        
        return node->height;
    }

    int balanceFactor(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        
        return height(node->left) - height(node->right); 
    }

    void updateHeight(Node *node)
    {
        if (node != NULL)
        {
            node->height = 1 + max(height(node->left), height(node->right) );
        }
        
    }


    Node* rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;
        
        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node *rotateLeft(Node *y)
    {
        Node *x = y->right;
        Node *T2 = x->left;

        x->left = y;
        y->right = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node* insert(Node* node, int key)
    {
        if (node == NULL)
        {
            return new Node(key);
        }
        
        if (key < node->key)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = insert(node->right, key);   
        }
        else
        {
            return node;
        }
        
        updateHeight(node);

        int balance = balanceFactor(node);

        if (balance > 1)
        {
            if (key < node->left->key)
            {
                return rotateRight(node);
            }
            else
            {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        if (balance < -1)
        {
            if (key > node->right->key)
            {
                return rotateLeft(node);
            }
            else
            {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
            
        }
        
        return node;
    }

    void inorderTraversal(Node* node)
    {
        if (node != NULL)
        {
            inorderTraversal(node->left);
            cout<<node->key<<" ";
            inorderTraversal(node->right);
        }
        
    }

    AVLTree() : root(NULL){}

    void insert(int key)
    {
        root = insert(root, key);
    }

    void inorderTraversal()
    {
        inorderTraversal(root);
        cout<<endl;
    }

};



int main()
{
    AVLTree avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    std::cout << "Inorder Traversal: ";
    avl.inorderTraversal();

    return 0;
}