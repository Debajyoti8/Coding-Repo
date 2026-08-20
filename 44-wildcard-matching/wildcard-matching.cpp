class Solution {
public:

    bool isMatch(string s, string p) {
        //Space opt bt 1-based imp 
        //tc-O(nm)
        //sc-O(m)
        int n=s.size();
        int m=p.size();
        vector<bool> prev(m+1,0);

        //base cases                      
        prev[0]=1;
        // for(int i=1;i<=n;i++) dp[i][0]=0; //this base case wil be used in loops  
        for(int j=1;j<=m;j++)
        {
            if(p[j-1]=='*')
                prev[j]=prev[j-1];
        }

        for(int i=1;i<=n;i++)
        {
            vector<bool> curr(m+1,0);
            curr[0]=0;
            for(int j=1;j<=m;j++)
            {
                //copy recurrence
                // explore all combintn
                //if match
                if(s[i-1]==p[j-1] | p[j-1]=='?')
                curr[j]=prev[j-1];
                //if no match in char of both strings
                else
                {
                    //if * is there
                    if(p[j-1]=='*')
                    curr[j]=prev[j] // * ek ya zyada chars match kare
                    |curr[j-1]; // * empty string match kare 
                    //if normal char is there
                    else
                    curr[j]=false;   //dp mai store hoga bcz match not possible at all             
                }
            }
            prev=curr;
        }

        return prev[m];
    }
};