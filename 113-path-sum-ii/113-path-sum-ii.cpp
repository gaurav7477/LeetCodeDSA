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
    vector<vector<int>> ans;
    void path_sum(TreeNode* root, int targetSum, vector<int> &path,int currSum){
       
        if(root == NULL) return;
        
        currSum += root->val;
        path.push_back(root->val);
        if(targetSum == currSum && root->left == NULL && root->right == NULL){
            ans.push_back(path);
        }
        path_sum(root->left,targetSum,path,currSum);
        path_sum(root->right,targetSum,path,currSum);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int> path;
        path_sum(root, targetSum, path,0);
        return ans;
    }
};