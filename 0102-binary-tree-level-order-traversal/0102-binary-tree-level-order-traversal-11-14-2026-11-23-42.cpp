
class Solution {
public:
    int levelOfTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        return 1 + max(levelOfTree(root->left),
                       levelOfTree(root->right));
    }

    void Nthleveldisplay(TreeNode* root, int curr,
                         int level, vector<int>& st) {

        if (root == NULL)
            return;

        if (curr == level) {
            st.push_back(root->val);
            return;
        }

        Nthleveldisplay(root->left, curr + 1, level, st);
        Nthleveldisplay(root->right, curr + 1, level, st);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        int n = levelOfTree(root);

        for (int i = 1; i <= n; i++) {

            vector<int> st;

            Nthleveldisplay(root, 1, i, st);

            ans.push_back(st);
        }

        return ans;
    }
};
