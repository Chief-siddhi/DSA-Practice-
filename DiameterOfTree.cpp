#include <iostream>
#include <algorithm>
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

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    return max(leftHt, rightHt) + 1;
}

int diam1(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int currDiam = height(root->left) + height(root->right) + 1;
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}
