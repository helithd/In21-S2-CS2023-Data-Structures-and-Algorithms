#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int key;
    struct node *left, *right;

};

struct node* newNode(int value)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
    {
        if (root == NULL)
            return;

        traverseInOrder(root->left);
        cout << root->key << " ";
        traverseInOrder(root->right);
    }
}


// Insert a node
struct node *insertNode(struct node *node, int key) {

    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);

    return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {

    if (root == NULL)
        return root;


    if (root->key > key) {
        root->left = deleteNode(root->left, key);
        return root;
    }
    else if (root->key < key) {
        root->right = deleteNode(root->right, key);
        return root;
    }


    if (root->left == NULL) {
        node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        node* temp = root->left;
        delete root;
        return temp;
    }


    else {
        node* nextParent = root;

        node* next = root->right;
        while (next->left != NULL) {
            nextParent = next;
            next = next->left;
        }

        if (nextParent != root)
            nextParent->left = next->right;
        else
            nextParent->right = next->right;

        root->key = next->key;

        delete next;
        return root;
    }
}

// Driver code
int main() {
    struct node *root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch(operation) {
            case 1: // insert
                cin >> operand;
                root = insertNode(root, operand);
                cin >> operation;
                break;
            case 2: // delete
                cin >> operand;
                root = deleteNode(root, operand);
                cin >> operation;
                break;
            default:
                cout << "Invalid Operator!\n";
                return 0;
        }
    }

    traverseInOrder(root);
}
