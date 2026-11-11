/**
 * Definition for a binary tree root.
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
    
void postOrder(TreeNode *root, vector<int> &res)
{
    if (root == nullptr)
        return;

    // First we traverse left subtree
    postOrder(root->left, res);

    // After visiting left, traverse right subtree
    postOrder(root->right, res);

    // now we visit root
    res.push_back(root->val);
}

    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> ans;
         postOrder(root,ans);
         return ans;   
    }
};