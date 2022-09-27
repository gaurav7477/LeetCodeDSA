/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void solveDown(TreeNode* root,vector<int> &ans,int pk, int k){
        
        if(pk == k) ans.push_back(root->val);
        if(root->left) solveDown(root->left,ans,pk+1,k);
        if(root->right) solveDown(root->right,ans,pk+1,k);
    }
    
    int dis(TreeNode* root, TreeNode* target, int k,vector<int> &ans){
        if(root == target){
            solveDown(root,ans,0,k);
            return 0;
        }
        if(root->left == NULL && root->right ==NULL) return -1;
        int left_dis = -1;
        int right_dis = -1;
        int temp_k = -1;
        
        if(root->left) left_dis = dis(root->left,target,k,ans) ;
        if(root->right) right_dis = dis(root->right,target,k,ans) ;
        
        // cout<<root->val<<" -> "<<left_dis<<" , "<<right_dis<<endl;
        
        if(left_dis != -1)  {
            temp_k = left_dis +1;
            if(root->right) solveDown(root->right,ans, temp_k+1,k);
        }
        if(right_dis != -1)  {
            temp_k = right_dis +1;
            if(root->left) solveDown(root->left,ans, temp_k+1,k);
        }
        
        if(temp_k == -1) return -1;
        else if(temp_k == k){ 
            ans.push_back(root->val);
            return k;
        }
        else return temp_k;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        dis(root,target,k,ans);
        return ans;
    }
};