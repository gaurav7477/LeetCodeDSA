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
    TreeNode* minimumVal(TreeNode* root){
        TreeNode* temp = root;
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        
        if(root->val == key){
            //0 chilid
            if(root->left == NULL && root->right == NULL){
                TreeNode* temp = root;
                delete root;
                return NULL;
            }
             //1 LEFT chilid
            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;  
            }
             //1 RIGHT chilid
            if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
             //2 LEFT AND RIGHT chilid
            if(root->left != NULL && root->right != NULL){
                int mini = minimumVal(root->right)->val;
                root->val = mini;
                cout<< mini;
                root->right = deleteNode(root->right,mini);
                return root;
            }
        }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else{
            root->right = deleteNode(root->right,key);
        }
    
        return root;
    }
    
};