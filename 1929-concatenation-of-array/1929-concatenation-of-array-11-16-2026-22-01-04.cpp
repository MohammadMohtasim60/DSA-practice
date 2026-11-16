class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> st;

        for(int i = 0; i < nums.size(); i++) {
        st.push_back(nums[i]);
        }

        for(int i = 0; i < nums.size(); i++) {
        st.push_back(nums[i]);
        }
        return st;
    }
};