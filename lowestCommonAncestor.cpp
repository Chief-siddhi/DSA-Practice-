#include <iostream>
#include <vector>
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

bool rootToNodePath(Node* root, int n, vector<int> &path) {
    if (root == NULL) {
        return false;
    }

    path.push_back(root->data);

    if (root->data == n) {
        return true;
    }

    if (rootToNodePath(root->left, n, path) ||
        rootToNodePath(root->right, n, path)) {
        return true;
    }

    // Backtrack
    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2) {
    vector<int> path1, path2;

    if (!rootToNodePath(root, n1, path1) ||
        !rootToNodePath(root, n2, path2)) {
        return -1; // if any node not found
    }

    int lca = -1;
    int i = 0;

    while (i < path1.size() && i < path2.size()) {
        if (path1[i] != path2[i]) {
            break;
        }
        lca = path1[i];
        i++;
    }

    return lca;
}
