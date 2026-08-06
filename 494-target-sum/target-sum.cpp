class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int target) {
        //Tabulation code
        // Time: O(n × sum)
        // Space:O(n × sum)
        int n=nums.size();
        int total=0;
        for(auto x:nums) total+=x;

        //edge cases
        if(total - target < 0 || (total - target) % 2)
            return 0;

        int sum=(total - target)/2;    //we need subset with sum named sum
        vector<vector<int>> dp(n,vector<int>(sum+1,0));

        //base cases
        if(nums[0] == 0)
            dp[0][0] = 2;
        else
        {
            dp[0][0] = 1;

            if(nums[0] <= sum)  //Array index out of bounds se bachne ke liye
                dp[0][nums[0]] = 1;
        }

        // Fill DP table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= sum; j++) {

                int nottake = dp[i - 1][j];

                int take = 0;
                if (nums[i] <= j)
                    take = dp[i - 1][j - nums[i]];

                dp[i][j] = take + nottake;
            }
        }

        return dp[n - 1][sum];
    }
};