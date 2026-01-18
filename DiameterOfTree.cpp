#include <iostream>
#include <algorithm>
#include<vector>
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
int idx = 0;

Node* buildTree(vector<int>& nodes) {
    if (nodes[idx] == -1) {
        idx++;
        return NULL;
    }

    Node* root = new Node(nodes[idx++]);
    root->left = buildTree(nodes);
    root->right = buildTree(nodes);

    return root;
}


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

pair<int, int> diam2(Node* root){
    if(root==NULL){
        return make_pair(0,0);
    }

    pair<int,int> leftInfo = diam2(root->left);
    pair<int,int> rightInfo = diam2(root->right);

    int currDiam = leftInfo.second + rightInfo.second +1;
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second)+1;

    return make_pair(finalDiam, finalHt);

}
int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    cout<<"diameter = "<<diam2(root).first<<endl;
}