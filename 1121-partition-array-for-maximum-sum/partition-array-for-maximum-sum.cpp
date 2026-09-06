class Solution {
public:

    int f(int i,int n,vector<int>& arr,int k,vector<int>& dp)
    {
        // All elements are partitioned
        if(i==n) return 0;

        // Already calculated
        if(dp[i]!=-1) return dp[i];

        int maxi=-1e9, len=0, ans=-1e9;

        // Try all possible partitions of length <= k
        for(int j=i;j<min(n,i+k);j++)
        {
            len++;

            // Maximum element in current partition
            maxi=max(maxi,arr[j]);

            // Current partition sum + best answer for remaining elements
            int cost=maxi*len + f(j+1,n,arr,k,dp);

            // Choose the partition giving maximum sum
            ans=max(ans,cost);
        }

        return dp[i]=ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr,int k)
    {
        // Memoization
        // Time: O(n * k)
        // Space: O(n) DP + O(n) recursion stack = O(n)

        int n=arr.size();
        vector<int> dp(n,-1);

        return f(0,n,arr,k,dp);
    }
};