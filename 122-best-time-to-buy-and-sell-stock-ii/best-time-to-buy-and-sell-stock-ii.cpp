class Solution {
public:

    int maxProfit(vector<int>& prices) {
        //Space opt code
        //Time - O(2*n)
        //Space - O(2+2) 
        int n=prices.size();
        vector<int> ahead(2,0);

        //base case
        ahead[0]=ahead[1]=0;

        //explore
        for(int i=n-1;i>=0;i--)
        {
            vector<int> curr(2,0);
            for(int buy=0;buy<2;buy++)
            {
                //copy recursion code
                int profit=0;
                if(buy) //if not buy till  now,just buy it
                profit=max(-prices[i] + ahead[0], ahead[1]); //max(buy, skip)
                else    //sell
                profit=max(prices[i] + ahead[1], ahead[0]);

                curr[buy]=profit;
            }
            ahead=curr;
        }

        return ahead[1];
    }
};