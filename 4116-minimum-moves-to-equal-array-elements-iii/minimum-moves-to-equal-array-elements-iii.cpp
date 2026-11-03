class Solution {
public:
    int minMoves(vector<int>& nums) {
        // TC: O(2N)
        // SC: O(1) auxiliary space

        int maxi = *max_element(nums.begin(), nums.end());

        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            ans += maxi - nums[i];
        }

        return ans;
    }
};