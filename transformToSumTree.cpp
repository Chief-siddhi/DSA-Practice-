//Transform of sum tree

#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int transform(Node* root) {
    if (root == NULL) {
        return 0;
    }

    // Step 1: transform left & right subtrees
    int leftSum = transform(root->left);
    int rightSum = transform(root->right);

    // Step 2: store old value
    int oldValue = root->data;

    // Step 3: update current node
    root->data = leftSum + rightSum;

    // Step 4: return total sum INCLUDING old value
    return leftSum + rightSum + oldValue;
}
