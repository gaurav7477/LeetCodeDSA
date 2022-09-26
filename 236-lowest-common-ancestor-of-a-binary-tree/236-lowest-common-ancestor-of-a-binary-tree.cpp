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
    
//     bool lca(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* ans){
//         if(root->val == p || root->val == q) return true;
        
//         if(root == NULL) return false;
        
//         bool left = lca(root->left,p,q,ans);
//         if(left)
//         bool right = lca(root->right,p,q,ans);
//     }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        if(left == NULL) return right;
        if(right == NULL) return left;
        else{
            return root;
        }

    }
};