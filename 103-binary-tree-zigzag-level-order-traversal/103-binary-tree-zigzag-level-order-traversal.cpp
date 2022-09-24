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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    
        vector<vector<int>> final_ans;
        if(root == NULL) return final_ans;
        queue<TreeNode*>q;
        q.push(root);
        int leftToRight = true;
    
        
        while(!q.empty()){
            
            int size =  q.size();
            vector<int> ans(size);
            
            for(int i = 0; i <size;i++){
                TreeNode* temp = q.front();
                q.pop();
               
                // find the position to fill the node
                
               int index = leftToRight ? i : size-i-1;
               ans[index]  = temp->val;
              
                if(temp->left != NULL)  q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                
                // ans.push_back(temp->val);
            }
            
            leftToRight = !leftToRight;
            final_ans.push_back(ans);
           
        }
        return final_ans;
       
    }
};