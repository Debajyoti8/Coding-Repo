class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int target) {
        //Tabulation code
        // Time: O(n × sum)
        // Space:O(sum)
        int n=nums.size();
        int total=0;
        for(auto x:nums) total+=x;

        //edge cases
        if(total - target < 0 || (total - target) % 2)
            return 0;

        int sum=(total - target)/2;    //we need subset with sum named sum
        vector<int> prev(sum + 1, 0);

        // Base cases
        if (nums[0] == 0)
            prev[0] = 2;
        else {
            prev[0] = 1;

            if (nums[0] <= sum)
                prev[nums[0]] = 1;
        }

        // Fill DP
        for (int i = 1; i < n; i++) {

            vector<int> curr(sum + 1, 0);

            for (int j = 0; j <= sum; j++) {

                int nottake = prev[j];

                int take = 0;
                if (nums[i] <= j)
                    take = prev[j - nums[i]];

                curr[j] = take + nottake;
            }

            prev = curr;
        }

        return prev[sum];
    }
};