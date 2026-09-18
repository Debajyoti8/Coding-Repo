class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // TC: O(n^2)
        // SC: O(1)
        //Imp -ve nos also present

        int n = nums.size();

        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {

                // Check only the two selected elements
                if(nums[i] + nums[j] == target)
                    return {i, j};
            }
        }

        return {};
    }
};