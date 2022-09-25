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
    vector<int> rightSideView(TreeNode* root) {
         //Your code here
        vector<int>ans;
        if(root == NULL) return ans;
        
        // level,data
        map<int,int>topNode;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            auto p =  q.front();
            q.pop();
            TreeNode *frontNode = p.first;
            
            int level = p.second;
            
             topNode[level] = frontNode->val;
            
            if(frontNode->left) q.push({frontNode->left, level+1});
            if(frontNode->right) q.push({frontNode->right, level+1});
           
            
        }
        for(auto i : topNode){
            ans.push_back(i.second);
        }
        return ans;
    }
};