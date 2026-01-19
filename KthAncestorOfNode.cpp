//Kth node of ancestor


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

int kthAncestor(Node* root, int node, int K){
    if(root==NULL){
        return -1;
    }
    if(root->data == node){
        return 0;
    }
    int leftDist = kthAncestor(root->left, node, K);
    int rightDist = kthAncestor(root->right, node, K);

    if(leftDist ==-1 && rightDist==-1){
        return -1;
    }

    int validValue = leftDist == -1 ? rightDist : leftDist;
    if(validValue +1 ==K){
        cout<<"Kth ancestor : "<<root->data<<endl;
    }
    return validValue+1;
}