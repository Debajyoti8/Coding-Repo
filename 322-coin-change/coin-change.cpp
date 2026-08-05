class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        //Space
        // Time Complexity: O(n × amount)
        // Space Complexity: O( amount)
        int n=coins.size();
        vector<int> prev(amount+1,0);

        //base cases for index 0
        for(int t=0;t<=amount;t++)
        {
            if(t%coins[0]==0)
            prev[t]=t/coins[0];
            else 
            prev[t]=1e9;
        }

        //change parameters
        for(int i=1;i<n;i++)
        {
           vector<int> curr(amount+1,0);
           for(int t=0;t<=amount;t++)
           {
                //copy recursion code
                int pick=1e9;
                if(coins[i]<=t)
                pick=1+ curr[t-coins[i]];
                int notpick=prev[t];

                curr[t]=min(pick,notpick);
           }
           prev=curr;
        }

        int ans = prev[amount];


        if(ans >= 1e9)
            return -1;

        return ans;
    }
};