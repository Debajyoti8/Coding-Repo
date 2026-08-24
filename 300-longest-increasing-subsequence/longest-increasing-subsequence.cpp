class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        //Tabulation diff approach striver
        //Time  : O(n^2)
        // Space :O(n)
        int n=nums.size();
        
        vector<int> dp(n,1); //min 1 size ka LIS hoga hi hoga
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev]<nums[i])
                dp[i]=max(1 + dp[prev] , dp[i]);
            }
            maxi=max(maxi,dp[i]);
        }

        return maxi;
    }
};