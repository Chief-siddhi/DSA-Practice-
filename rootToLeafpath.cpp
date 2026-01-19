// Root to leaf path
//this ques can be for bst or can be for any tree
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
void printPath(vector<int> path){
    cout<< "path: "<<" ";
    for(int i=0; i<path.size(); i++){
        cout<<path[i]<<" ";
    } cout<<endl;
}
void pathHelper(Node* root, vector<int> &path){
    if(root== NULL){
        return;
    }
    path.push_back(root->data);

    if(root->left == NULL && root->right == NULL){
        printPath(path);
        path.pop_back();
        return;
    }
    pathHelper(root->left, path);
    pathHelper(root->right, path);
    path.pop_back();
}
void rootToLeafPath(Node* root){
    vector<int> path;
    pathHelper(root, path);
}