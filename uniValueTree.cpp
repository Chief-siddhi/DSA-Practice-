#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool uniValue(TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    if (!uniValue(root->left) || !uniValue(root->right)) {
        return false;
    }

    if (root->left != NULL) {
        if (root->val != root->left->val) {
            return false;
        }
    }

    if (root->right != NULL) {
        if (root->val != root->right->val) {
            return false;
        }
    }

    return true;
}
