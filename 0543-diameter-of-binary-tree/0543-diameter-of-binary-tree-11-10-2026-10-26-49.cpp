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

void helper(TreeNode* root ,int &maxD){
    if(root == NULL) return;
    int D = LevelOfTree(root->left) + LevelOfTree(root->right);
    maxD = max(D,maxD);
    helper(root->left,maxD);
    helper(root->right,maxD);
}

int diameterOfBinaryTree(TreeNode* root) {
        int maxD = 0;
        helper(root,maxD);
        return maxD;
}
};