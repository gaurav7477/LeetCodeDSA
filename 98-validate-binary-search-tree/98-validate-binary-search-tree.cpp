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
    bool validBstByRange(TreeNode* root,long long min,long long max){
        // base case
        if(root == NULL) return true;
        
        if(root->val > min && root->val < max){
            bool left = validBstByRange(root->left,min,root->val);
            bool right = validBstByRange(root->right,root->val,max);
            return left && right;
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        long long min = LONG_MIN;
        long long max = LONG_MAX;
        return validBstByRange(root,min,max);
    }
};