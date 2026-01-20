//Validate BST
//node > maxValue in left subtree
//node < minValue in right subtree
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
bool validateHelper(Node* root, Node* min, Node* max){
    if(root==NULL){
        return true;
    }
    if(min != NULL && root->data < min->data){
        return false;
    }
    if(max != NULL && root-> data > max->data){
        return false;
    }
    return validateHelper(root->left,min, root)
          && validateHelper(root->right, root, max);
}

bool validateBST(Node* root){
    return validateHelper(root, NULL, NULL);
}