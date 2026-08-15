class Solution {
public:

    int f(int i,int j,string &s, string &t,vector<vector<int>> &dp)
    {
        //base case
        if(j<0) return 1; //s2 matches
        if(i<0) return 0; //s2 not matches but s1 has no elem left
        if(dp[i][j]!=-1) return dp[i][j];

        //explore all possibilities
        if(s[i]==t[j])
        return dp[i][j]=f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
        else 
        return dp[i][j]=f(i-1,j,s,t,dp);
    }

    int numDistinct(string s, string t) {
        //Memoization
        //tc-O(nm)
        //sc-O(nm)+o(n+m)
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }
};