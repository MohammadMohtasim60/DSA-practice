/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
//  */
// class Solution {
// public:
//     bool exist(TreeNode* root,TreeNode* target){
//         if(root == NULL) return false;
//         if(root == target ) return true;
//         return exist(root->left , target) || exist(root -> right, target);
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//          if(root == p || root == q) return root; 
//          else if(exist(root -> left  , p) && exist(root->right ,q ) )  
//             return root;
//         else if(exist(root->right ,p) && exist(root -> left , q))       
//             return root;
//         else if(exist(root->left ,p) && exist(root -> left ,q))       
//             return lowestCommonAncestor(root-> left ,p , q);
//         else 
//             return lowestCommonAncestor(root-> right ,p,q);
//     }
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(
        TreeNode* root, TreeNode* p, TreeNode* q) {

        // Base condition
        if (root == NULL || root == p || root == q)
            return root;

        // Search in left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // Both nodes found in different subtrees
        if (left != NULL && right != NULL)
            return root;

        // Return the non-NULL result
        if (left != NULL)
            return left;

        return right;
    }
};
