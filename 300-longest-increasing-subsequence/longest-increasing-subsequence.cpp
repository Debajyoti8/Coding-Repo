class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        //Tabulation
        //Time  : O(n^2)
        // Space :O(n^2)
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0)); //dp mai 1 prev_idx shift krke store krna hai 

        // base case already covered

        for(int i=n-1;i>=0;i--)
        {
            for(int prev=i-1;prev>=-1;prev--)
            {
                //copy recursion
                //max(pick,not pick)        
                //Not pick
                int len=dp[i+1][prev+1];   //co-ordinate shift has to be done
                //pick
                if(prev==-1||nums[i]>nums[prev]) 
                len=max(len,1 + dp[i+1][i+1]);

                dp[i][prev+1]=len;
            }
        }

        return dp[0][-1+1] ; //co-ordinate shift has to be done
    }
};