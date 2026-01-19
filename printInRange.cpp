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
void(printInRange(Node*root, int start, int end)){
    if(root== NULL){
        return;
    }
    if(start <= root->data && root->data <= end){ //case1
        cout<< root->data << " ";
        printInRange(root->left, start, end);
        printInRange(root->right, start, end);
    } else if(root->data < start){  //case2
        printInRange(root->right, start, end);
    } else{  //case3
        printInRange(root->left, start, end);
    }
}
