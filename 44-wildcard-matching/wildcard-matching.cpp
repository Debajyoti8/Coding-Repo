class Solution {
public:

    int f(int i,int j,string &s, string &p,vector<vector<int>> &dp)
    {
        //base cases
        //if p gets exhausted
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        //if s gets exhausted
        if(i<0 && j>=0)
        {
            for(int x=0;x<=j;x++)
            {
                if(p[x]!='*')
                return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        // explore all combintn
        //if match
        if(s[i]==p[j] || p[j]=='?')
        return dp[i][j]=f(i-1,j-1,s,p,dp);
        //if no match in char of both strings
        else
        {
            //if * is there
            if(p[j]=='*')
            return dp[i][j]=f(i-1,j,s,p,dp) // * ek ya zyada chars match kare
            ||f(i,j-1,s,p,dp); // * empty string match kare 
            //if normal char is there
            else
            return dp[i][j]=false;   //dp mai store hoga bcz match not possible at all             
        }
    }

    bool isMatch(string s, string p) {
        //Memoization
        //tc-O(nm)
        //sc-O(nm)+O(n+m)
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,p,dp);
    }
};