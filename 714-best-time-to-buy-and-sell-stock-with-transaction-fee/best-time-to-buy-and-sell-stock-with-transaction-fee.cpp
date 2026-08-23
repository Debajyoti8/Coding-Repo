class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {
        //Space opt code using 4 variable instead of 2 1D vector
        //Time - O(n) 
        //Space- O(4)=O(1) 
        int n=prices.size();
        int frontNotBuy=0,frontBuy=0;
        int currNotBuy=0,currBuy=0;

        //base acse covered
        for(int i=n-1;i>=0;i--)
        {
            //Buy
                currBuy=max(-prices[i] + frontNotBuy ,frontBuy); //max(buy, skip)
            //if sell /skip
                currNotBuy=max(prices[i]-fee + frontBuy , frontNotBuy);       

                frontNotBuy=currNotBuy; 
                frontBuy= currBuy;       
        }

        return frontBuy;
    }
};