class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long ans=0;
        if(!root) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            long start=q.front().second;
            long end=q.back().second;
            ans=max(end-start+1,ans);
            while(sz--){
                TreeNode* temp=q.front().first;
                long idx=q.front().second;
                q.pop();
                if(temp->left) q.push({temp->left,2*idx+1});
                if(temp->right) q.push({temp->right,2*idx+2});
            }
        }
        return ans;
    }
};