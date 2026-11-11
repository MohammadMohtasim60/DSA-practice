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
    bool isMirror(TreeNode* lroot,TreeNode* Rroot){
        if(lroot == NULL && Rroot == NULL)
        return true;
        if(lroot == NULL || Rroot == NULL || lroot ->val != Rroot->val)
        return false;
        return isMirror( lroot->left , Rroot->right) && 
        isMirror( lroot->right , Rroot->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        
        return isMirror(root->left , root->right);
    }
};