#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data; 
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right=NULL;
    }
};
Node* buildBSTfromSorted(int arr[], int st, int end){
    if(st>end){
        return NULL;
    }
    int mid = st+(end-st)/2;
    Node* curr = new Node(arr[mid]);
    curr->left = buildBSTfromSorted(arr, st, mid-1);
    curr->right = buildBSTfromSorted(arr, mid+1, end);

    return curr;
};