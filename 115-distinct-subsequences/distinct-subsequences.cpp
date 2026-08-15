class Solution {
public:

    int numDistinct(string s, string t) {
        //Tabulation 1-based idx to avoid neg indexing
        //tc-O(nm)
        //sc-O(nm)
        int n=s.size();
        int m=t.size();
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));

        //base cases
        for(int i=0;i<=n;i++)
        dp[i][0]=1; 
        //2nd base case already covered due to initialising with 0
        
        //use nested loops 
        for(int i=1;i<=n;i++) //i=0 base case already covered
        {
            for(int j=1;j<=m;j++)
            {
                //explore all possibilities               
                    if(s[i-1]==t[j-1])
                    dp[i][j]= dp[i-1][j-1]+dp[i-1][j]; 
                    else 
                    dp[i][j]=dp[i-1][j]; 
                
            }
        }

        return (int)dp[n][m];
    }
};