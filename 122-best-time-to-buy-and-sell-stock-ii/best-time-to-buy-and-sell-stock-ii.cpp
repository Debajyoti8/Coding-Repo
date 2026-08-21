class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,n=prices.size();
        int mini=prices[0];  //stores min buy price

        for(int i=1;i<n;i++)
        {
            int cost=prices[i]-mini;
            if(cost>0) 
            {
                profit+=cost;
                mini=prices[i]; 
            }
            else
            mini=min(mini,prices[i]);    
        }

        return profit;
    }
};