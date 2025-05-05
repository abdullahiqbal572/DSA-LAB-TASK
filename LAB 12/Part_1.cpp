#include<iostream>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;

    Node(int k = 0) {
        key = k;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class Avl {
    Node* root;

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    int height(Node* N) {
        if (N == NULL) return 0;
        return N->height;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* t2 = x->right;

        x->right = y;
        y->left = t2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* t2 = y->left;

        y->left = x;
        x->right = t2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    Node* deleteNodeHelper(Node* node, int key) {
        if (node == NULL) return node;

        if (key < node->key)
            node->left = deleteNodeHelper(node->left, key);
        else if (key > node->key)
            node->right = deleteNodeHelper(node->right, key);
        else {
            if (node->left == NULL || node->right == NULL) {
                Node* temp = node->left ? node->left : node->right;

                if (temp == NULL) {
                    temp = node;
                    node = NULL;
                } 
                else { 
                    *node = *temp; 
                }
                delete temp;
            } 
            else {
                Node* temp = minValueNode(node->right);
                node->key = temp->key;
                node->right = deleteNodeHelper(node->right, temp->key);
            }
        }

        if (node == NULL) return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalancedFactor(node);

        if (balance > 1 && getBalancedFactor(node->left) >= 0)
            return rightRotate(node);

        if (balance > 1 && getBalancedFactor(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && getBalancedFactor(node->right) <= 0)
            return leftRotate(node);

        if (balance < -1 && getBalancedFactor(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* insertNode(Node* node, int key) {
        if (node == NULL)
            return new Node(key);

        if (key < node->key)
            node->left = insertNode(node->left, key);
        else if (key > node->key)
            node->right = insertNode(node->right, key);
        else 
            return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalancedFactor(node);

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

public:
    Avl() {
        root = NULL;
    }

    int getBalancedFactor(Node* node) {
        if (node == NULL) return 0;
        return height(node->left) - height(node->right);
    }

    void insert(int key) {
        root = insertNode(root, key);
    }

    void deleteNode(int key) {
        root = deleteNodeHelper(root, key);
    }

    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->key << " -> ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node != NULL) {
            cout << node->key << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    Node* getRoot() const { return root; }
};

int main() {
    int nodes[] = {10, 20, 30, 40, 50, 25};
    Avl avl;

    for (int key : nodes) {
        avl.insert(key);
    }

    cout << "Preorder traversal before deletion: ";
    avl.preorder(avl.getRoot());
    cout << endl;

    avl.deleteNode(30);

    cout << "Preorder traversal after deletion: ";
    avl.preorder(avl.getRoot());
    cout << endl;

    return 0;
}
