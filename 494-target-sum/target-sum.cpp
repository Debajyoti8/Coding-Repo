class Solution {
public:
    int f(int i,vector<int>& nums,int sum,vector<vector<int>> &dp)
    {
        if(i==0)
        {
            if(sum==0 && nums[0]==0)
            return 2;
            else if(sum==0 || nums[0]==sum)
            return 1;
            else 
            return 0;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];

        int nottake = f(i-1, nums, sum,dp);

        int take = 0;
        if(nums[i] <= sum)
            take = f(i-1, nums, sum-nums[i],dp);


        return dp[i][sum]=take + nottake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        //Memoization code
        // Time: O(n × sum)
        // Space:O(n × sum)+ O(n) (recursion stack)
        int n=nums.size();
        int total=0;
        for(auto x:nums) total+=x;

        //edge cases
        if(total - target < 0 || (total - target) % 2)
            return 0;

        int sum=(total - target)/2;    //we need subset with sum named sum
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));

        return f(n-1,nums,sum,dp);
    }
};