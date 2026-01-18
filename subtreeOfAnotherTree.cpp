#include <iostream>
#include <vector>
using namespace std;

/* -------- Node definition -------- */
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

/* -------- Build Tree (Preorder) -------- */
int idx = 0;

Node* buildTree(vector<int>& nodes) {
    if (idx >= nodes.size() || nodes[idx] == -1) {
        idx++;
        return NULL;
    }

    Node* root = new Node(nodes[idx++]);
    root->left = buildTree(nodes);
    root->right = buildTree(nodes);

    return root;
}

/* -------- Check if two trees are identical -------- */
bool isIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    return (root1->data == root2->data) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

/* -------- Subtree Check -------- */
bool isSubtree(Node* root, Node* subRoot) {
    if (subRoot == NULL)
        return true;

    if (root == NULL)
        return false;

    if (isIdentical(root, subRoot))
        return true;

    return isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
}

/* -------- Main Function -------- */
int main() {
    vector<int> rootNodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    vector<int> subNodes  = {2, 4, -1, -1, 5, -1, -1};

    idx = 0;
    Node* root = buildTree(rootNodes);

    idx = 0;
    Node* subRoot = buildTree(subNodes);

    if (isSubtree(root, subRoot))
        cout << "subRoot is a subtree of root" << endl;
    else
        cout << "subRoot is NOT a subtree of root" << endl;

    return 0;
}
