class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Striver 
        //2nd method
        //Space opt code
        // Time-O(n×4)
        // Space-O(4) 
        int n=prices.size();

        //1d dp 
        vector<int> after(5,0);

        //base case already covered (i==n t==4)

        //explore
        for(int i=n-1;i>=0;i--) //loop starts in opp. fashion
        {
            vector<int> curr(5,0);
            for(int t=3;t>=0;t--)  //loop starts in opp. fashion
            {
                //copy recurrence
                    if(t%2==0) //if not buy till  now,just buy it
                        curr[t]=max(-prices[i] + after[t+1],after[t]); //max(buy, skip)
                    else    //sell 
                        curr[t]=max(prices[i]+after[t+1],after[t]);
                
            }
            after=curr;
        }

        //return will always be initial call made in recursion
        return after[0];
    }
};