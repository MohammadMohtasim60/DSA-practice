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
    // void preOrder(TreeNode* root,vector<int> & vc){
    //     if(root == NULL) return;
    //     vc.push_back(root->val);

    //     preOrder(root->left ,vc);
    //     preOrder(root->right,vc);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     preOrder(root,ans);
    //     return ans;
    // }

vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;
        stack<TreeNode*> st;

        if(root != NULL)
            st.push(root);

        while(!st.empty()) {

            TreeNode* temp = st.top();
            st.pop();

            ans.push_back(temp->val);

            if(temp->right != NULL)
                st.push(temp->right);

            if(temp->left != NULL)
                st.push(temp->left);
        }

        return ans;
    }
};