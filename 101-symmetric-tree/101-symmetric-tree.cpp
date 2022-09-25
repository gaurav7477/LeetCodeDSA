/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void postOrder(TreeNode* root,vector<int>&ans2){
        
         if(root == NULL){
            ans2.push_back(0);
            return;
        } 
        
        ans2.push_back(root->val);
        postOrder(root->right,ans2);
        
        postOrder(root->left,ans2);
        // ans2.push_back(root->val);
        
    }
    void preOrder(TreeNode* root,vector<int>&ans1){
        
        if(root == NULL){
            ans1.push_back(0);
            return;
        } 
        ans1.push_back(root->val);
        preOrder(root->left,ans1);
       
        preOrder(root->right,ans1);
        // preOrder(root->right,ans1);
        
    }
    
    bool isSymmetric(TreeNode* root) {
        vector<int>ans1,ans2;
        preOrder(root->left,ans1);
        postOrder(root->right,ans2);
        if( ans1 == ans2 ) return true;
        else return false;
    }
    
};