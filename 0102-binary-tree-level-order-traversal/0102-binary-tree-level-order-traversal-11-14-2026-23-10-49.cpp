
class Solution {
public:

    int levelOfTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        return 1 + max(levelOfTree(root->left),
                       levelOfTree(root->right));
    }

    void Nthleveldisplay(TreeNode* root, int level,
                         vector<vector<int>>& st) {
        if (root == NULL) return;

        st[level].push_back(root->val);

        Nthleveldisplay(root->left, level + 1, st);
        Nthleveldisplay(root->right, level + 1, st);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        int n = levelOfTree(root);

        for (int i = 0; i < n; i++) {
            vector<int> st;
            ans.push_back(st);
        }

        Nthleveldisplay(root, 0, ans);

        return ans;
    }


    // void Nthleveldisplay(TreeNode* root, int ,
    //                      int level, vector<int>& st) {

    //     if (root == NULL)
    //         return;

    //     if ( == level) {
    //         st.push_back(root->val);
    //         return;
    //     }

    //     Nthleveldisplay(root->left,  + 1, level, st);
    //     Nthleveldisplay(root->right,  + 1, level, st);
    // }

    // vector<vector<int>> levelOrder(TreeNode* root) {

    //     vector<vector<int>> ans;

    //     if (root == NULL)
    //         return ans;

    //     int n = levelOfTree(root);

    //     for (int i = 1; i <= n; i++) {

    //         vector<int> st;

    //         Nthleveldisplay(root, 1, i, st);

    //         ans.push_back(st);
    //     }

    //     return ans;
    // }
};
