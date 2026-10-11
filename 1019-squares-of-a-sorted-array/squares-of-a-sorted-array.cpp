class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // TC: O(n log n) — multiset insertion dominates
        // SC: O(n) — multiset stores all elements
        int n=nums.size();
        for(int i=0;i<n;i++)
        nums[i]*=nums[i];

        multiset<long long> st(nums.begin(),nums.end());
        vector<int> ans(st.begin(),st.end());

        return ans;
    }
};