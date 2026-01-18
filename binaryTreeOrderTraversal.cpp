// //binary tree order traversal 
// #include<iostream>
// #include<vector>
// using namespace std;

// vector<vector<int>> levelOrder(TreeNode* root){
//     vector<vector<int>> ans;
//     if(root==NULL){
//         return ans;
//     }
//     queue<TreeNode*> q;
//     q.push(root);
//     while(!q.empty()){
//         int size = q.size();
//         vector<int> level;
//         for(int i=0; i<size;i++){
//             TreeNode* curr = q.front();
//             q.pop();
//             level.push_bak(curr->val);
//             if(curr->left) q.push(curr->left);
//             if(curr->right) q.push(curr->right);
//         }
//     }
// }