class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {
        //Space opt code
        //Time - O(n) 
        //Space- O(2+2)=O(1) 
        int n=prices.size();
        vector<int> front(2,0);

        //base acse covered
        for(int i=n-1;i>=0;i--)
        {
             vector<int> curr(2,0);
                curr[1]=max(-prices[i] + front[0] ,front[1]); //max(buy, skip)
                //if sell cooldown occurs /skip
                curr[0]=max(prices[i]-fee + front[1] , front[0]);       

                front =curr;         
        }

        return front[1];
    }
};