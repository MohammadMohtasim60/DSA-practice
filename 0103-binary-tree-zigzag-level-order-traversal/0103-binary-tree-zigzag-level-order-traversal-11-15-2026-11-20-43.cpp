
class Solution {
public:
    int levelOfTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        return 1 + max(levelOfTree(root->left),
                       levelOfTree(root->right));
    }

    void leftToRight(TreeNode* root, int level,
                     vector<int>& st) {
        if (root == NULL)
            return;

        if (level == 1) {
            st.push_back(root->val);
            return;
        }

        leftToRight(root->left, level - 1, st);
        leftToRight(root->right, level - 1, st);
    }

    void RightTOLeft(TreeNode* root, int level,
                     vector<int>& st) {
        if (root == NULL)
            return;

        if (level == 1) {
            st.push_back(root->val);
            return;
        }

        RightTOLeft(root->right, level - 1, st);
        RightTOLeft(root->left, level - 1, st);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        int n = levelOfTree(root);

        for (int i = 1; i <= n; i++) {
            vector<int> st;

            if (i % 2 != 0)
                leftToRight(root, i, st);
            else
                RightTOLeft(root, i, st);

            ans.push_back(st);
        }

        return ans;
    }
};
