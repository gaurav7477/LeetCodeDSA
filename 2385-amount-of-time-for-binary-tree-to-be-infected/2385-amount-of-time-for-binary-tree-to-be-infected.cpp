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
    void solveDown(TreeNode* root,int pk, int& k){
        k = max(pk, k);
        if(root->left) solveDown(root->left,pk+1,k);
        if(root->right) solveDown(root->right,pk+1,k);
        // cout<<root->val <<" -> "<<pk<<" : " <<k<<endl;
        // cout<<"k: "<<k<<endl;
    }
    
    int dis(TreeNode* root, int target, int& k){
        if(root->val == target){
            solveDown(root,0,k);
            return 0;
        }
        if(root->left == NULL && root->right ==NULL) return -1;
        int left_dis = -1;
        int right_dis = -1;
        int temp_k = -1;
        
        if(root->left) left_dis = dis(root->left,target,k) ;
        if(root->right) right_dis = dis(root->right,target,k) ;
        
        // cout<<root->val<<" -> "<<left_dis<<" , "<<right_dis<<endl;
        
        if(left_dis != -1)  {
            temp_k = left_dis +1;
            if(root->right) solveDown(root->right, temp_k+1,k);
        }
        if(right_dis != -1)  {
            temp_k = right_dis +1;
            if(root->left) solveDown(root->left, temp_k+1,k);
        }
        // cout<<max(temp_k, k)<<endl;
        k = max(temp_k, k);
        if(temp_k == -1) return -1;
        else return temp_k;
    }
    // vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    //     vector<int>ans;
    //     dis(root,target,k,ans);
    //     return ans;
    // }
    int amountOfTime(TreeNode* root, int start) {
        int k = 0;
        dis(root, start, k);
        return k;
    }
};