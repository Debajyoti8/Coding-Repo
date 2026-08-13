class Solution {
public:

    int lcs(string &s,string &t)
    {
        //Tabulation code by right shifring (1-based indexing)
        int n=s.size(),m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        //base cases
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=0;i<=n;i++) dp[i][0]=0;

        //explore
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                //copy recursion
                //if match
                if(s[i-1]==t[j-1])
                dp[i][j]=1+ dp[i-1][j-1];
                //if not match
                else
                dp[i][j]=0 + max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[n][m];
    }

    int minDistance(string word1, string word2) {
        //Time Complexity  : O(n × m)
        // Space Complexity : O(n × m)
        int n=word1.size();
        int m=word2.size();

        return n+m-2*lcs(word1,word2);
    }
};