class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    int i = 0;
    while (i < nums1.size()) {

        int j = 0;

        while (j < nums2.size()) {

            if (nums1[i] == nums2[j]) {

                int k = 0;

                while (k < ans.size()) {
                    if (ans[k] == nums1[i])
                        break;

                    k++;
                }

                if (k == ans.size()) {
                    ans.push_back(nums1[i]);
                }
            }

            j++;
        }

        i++;
    }

    return ans;
    }
};