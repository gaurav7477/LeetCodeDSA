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
    int countNodes(TreeNode* root) {
        int count = 0;
         // vector<vector<int > >ans;
         if(root == NULL){
            return 0;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            // q.pop();
            vector<int>level;
            int size = q.size();
            for(int i = 0; i < size; i++){
                
                TreeNode* temp = q.front();
                q.pop();
                // swap(temp->left,temp->right);

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                // cout<<temp->val<<" ";
                
                if(temp->val == 0 || temp->val != 0){
                    count++;
                }
            }
        //     // cout<<level.size();
        // ans.push_back(level);
    }
        
        return count;
    }
};
