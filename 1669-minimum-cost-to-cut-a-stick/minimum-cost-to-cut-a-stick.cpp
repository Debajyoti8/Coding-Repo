class Solution {
public:

    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp)
    {
        // No cut left in this range
        if(i > j)
            return 0;

        // Already calculated
        if(dp[i][j] != -1)
            return dp[i][j];

        int mini = 1e9;

        // Try every cut as the FIRST cut in this range
        for(int ind = i; ind <= j; ind++)
        {
            // Current stick length
            // + cost of left part
            // + cost of right part
            int cost = cuts[j + 1] - cuts[i - 1]
                     + f(i, ind - 1, cuts, dp)
                     + f(ind + 1, j, cuts, dp);

            // Choose minimum among all possible first cuts
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        //Top-down
        //Time-O(c^2)*c=O(c^3)
        //space-O(c^2)+ASS
        int c=cuts.size();
        // Add boundaries of the stick
        cuts.push_back(n); 
        cuts.insert(cuts.begin(),0);
        // Sorting makes cuts[i-1] and cuts[j+1]
        // the boundaries of the current stick
        sort(cuts.begin(),cuts.end());

        // dp[i][j] = minimum cost to perform cuts i to j
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));

        return f(1,c,cuts,dp);
    }
};