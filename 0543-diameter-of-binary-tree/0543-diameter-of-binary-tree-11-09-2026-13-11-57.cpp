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
    int maxD = 0;
    int LevelOfTree(TreeNode* root) {
    if (root == NULL)   return 0;
    return 1 + max(LevelOfTree(root->left) , LevelOfTree(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)   return 0;
        int dia = ( LevelOfTree(root->left) + LevelOfTree(root->right) );
        maxD = max(maxD,dia);
        diameterOfBinaryTree(root -> left);
        diameterOfBinaryTree( root -> right);
        return maxD;
    }
};