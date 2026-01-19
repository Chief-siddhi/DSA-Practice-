//Delete in BST
//cases for a node:-
//1) no child(leaf node)
//2) 1 child
//3) 2 children

#include<iostream>
#include<vector>
using namespace std;
//phle ham node ko search krenge then delete krenge and delete ke liye upr mentioned three cases honge

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
Node* getInorderSuccessor(Node* root){
    while(root->left != NULL){
        root= root->left;
    }
    return root;
}
Node* delNode(Node* root, int val){
    if(root==NULL){
        return NULL;
    }
    if(val < root->data){
        root->left = delNode(root->left, val);
    } else if(val > root->data){
        root-> right = delNode(root->right, val);
    } else{
        //root== val
        // case1: 0 children
        if(root-> left == NULL && root->right == NULL){
            delete root; return NULL;
        } 

        //case2: 1 child
        if(root->left== NULL || root-> right == NULL){
            return root->left == NULL ? root->right : root->left;
        }
        //case 3: 2 children
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root-> right = delNode(root->right, IS->data);
        return root;
    }
    return root;
}

