// Kth level of a binary tree using recursion

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

void kThHelper(Node* root, int k, int currLevel) {
    if (root == NULL) {
        return;
    }

    if (currLevel == k) {
        cout << root->data << " ";
        return;
    }

    kThHelper(root->left, k, currLevel + 1);
    kThHelper(root->right, k, currLevel + 1);
}

void KthLevel(Node* root, int k) {
    kThHelper(root, k, 1);
    cout << endl;
}
