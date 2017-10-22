#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;



struct Node
{
    Node* left;
    Node* right;
    int data;
};

struct Node* newNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);

    cout << " " << root->data << " " ;

    inorder(root->right);    
}

void preorder(Node* root)
{
    if(root==NULL)
        return;

    cout << " " <<root->data << " ";

    preorder(root->left);

    preorder(root->right);
}

void postorder(Node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);

    postorder(root->right);

    cout << " " << root->data << " ";

}

void BFS_tree(Node* root)
{
    queue <Node*> FIFO;

    FIFO.push(root);

    while(!FIFO.empty())
    {
        Node* temp = FIFO.front();
        cout << " " <<temp->data << " ";

        if(temp->left != NULL)
            FIFO.push(temp->left);

        if(temp->right != NULL)
            FIFO.push(temp->right);

        FIFO.pop();
    }

}

void print_array(int* path, int len) 
{
    for ( int i = 0; i < len; i++ )
        cout << " " << path[i] << " ";
    cout << endl;
}

void print_paths(Node* root, int path[], int len)
{
    if (root == NULL)
        return;

    path[len] = root->data;
    len++;

    if(root->left == NULL && root->right == NULL)
    {
        print_array(path, len);
    }
    else
    {
        print_paths(root->left, path, len);
        print_paths(root->right, path, len);
    }
}


void all_root_to_leaves(Node* root)
{
    int path[1000];
    print_paths(root, path, 0);

}



//This is extra credit. Only turn it in after completing other questions
void sumPath(Node* root, int k)
{
    
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

// The calls for the above incomplete functions commented out purposefully. Please uncomment after you have completed all the above methods.
    cout << " Inorder: ";
    inorder(root);
    cout << endl;

    cout << " Preorder: ";
    preorder(root);
    cout << endl;

    cout << " Postorder: ";
    postorder(root);
    cout << endl;

    cout << " Breadth First: ";
    BFS_tree(root);
    cout << endl;

    cout << " All Paths: " << endl;
    all_root_to_leaves(root);
    cout << endl;

//    sumPath(root, 11);
}

