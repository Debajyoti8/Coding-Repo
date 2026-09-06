class Solution {
public:

    // Check whether s[i...j] is a palindrome
    bool isPal(int i, int j, string &s)
    {
        while(i < j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
                return 0;
        }
        return 1;
    }

    
    int minCut(string s) {
        // Tabulation
        // Time: O(n^3)
        // Space: O(n)
        int n = s.size();
        vector<int> dp(n+1, 0);

        //base case covered

        //loops
        for(int i=n-1;i>=0;i--)
        {
            int mini = 1e9;   // reset for every i
            //copy recurrence
            // Try every possible ending position j
            for(int j = i; j < n; j++)
            {
                // If s[i...j] is palindrome, make a partition
                if(isPal(i, j, s))
                {
                    int cost = 1 + dp[j+1];
                    mini = min(mini, cost);
                }
            }

            dp[i] = mini;
        }
         
        return dp[0] - 1;
    }
};