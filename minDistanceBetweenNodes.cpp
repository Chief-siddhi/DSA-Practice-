#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// LCA using single traversal
Node* LCA2(Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == n1 || root->data == n2) {
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

// Distance from root to a given node
int dist(Node* root, int n) {
    if (root == NULL) {
        return -1;
    }

    if (root->data == n) {
        return 0;
    }

    int leftDist = dist(root->left, n);
    if (leftDist != -1) {
        return leftDist + 1;
    }

    int rightDist = dist(root->right, n);
    if (rightDist != -1) {
        return rightDist + 1;
    }

    return -1;
}

// Minimum distance between two nodes
int minDist(Node* root, int n1, int n2) {
    Node* lca = LCA2(root, n1, n2);

    if (lca == NULL) return -1;

    int dist1 = dist(lca, n1);
    int dist2 = dist(lca, n2);

    return dist1 + dist2;
}
