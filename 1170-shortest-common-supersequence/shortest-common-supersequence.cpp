class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        //step 1-Find lcs dp array 
        //Tabulation code by right shifring (1-based indexing)
        //Time: O(n × m)
        //Space:DP: O(n × m)
        int n=s1.size(),m=s2.size();
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
                if(s1[i-1]==s2[j-1])
                dp[i][j]=1+ dp[i-1][j-1];
                //if not match
                else
                dp[i][j]=0 + max(dp[i-1][j],dp[i][j-1]);
            }
        }

        //Step 2- start from last and find SCC
        int i=n,j=m;
        string ans="";
        //when we get common elem they will be counted only once
        while(i>0 && j>0) 
        {
            if(s1[i-1]==s2[j-1])
            {
                ans+=s1[i-1];
                i--,j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                ans+=s1[i-1];
                i--;
            }
            else
            {
                ans+=s2[j-1];
                j--;
            }
        }
        //Step 3- if still few char from any str remains
        while(i>0)
        {
            ans+=s1[i-1];
            i--;
        }
        while(j>0)
        {
            ans+=s2[j-1];
            j--;
        }

        //we got reversed ans so revrese it
        reverse(ans.begin(),ans.end());
        return ans;

    }
};