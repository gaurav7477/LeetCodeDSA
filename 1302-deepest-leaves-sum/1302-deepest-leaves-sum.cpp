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
    int deepestLeavesSum(TreeNode* root) {
        
        if(root->left == NULL && root->right == NULL) return root->val;
        int sum = 0;
        int last_sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL); // for count level
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                if(q.size() == 0){
                    last_sum = sum; 
                    break;
                }
                
                q.push(NULL);
                sum = 0;
                
            }
            else{
                sum += temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
            }
        }
        return last_sum;
    }
};