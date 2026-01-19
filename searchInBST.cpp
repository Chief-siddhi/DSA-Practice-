//search in BST

// #include<iostream>
// #include<vector>
// using namespace std;

// bool search(Node* root, int key){  //O(height) ; avg->O(logn)
//     if(root==NULL){
//         return false;
//     }
//     if(root->data == key){
//         return true;
//     }
//     if(root->data > key){
//         return search(root->left, key);
//     } else{
//         return search(root->right, key);
//     }
// }