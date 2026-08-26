class Solution {
public:

    bool check(string &s1,string &s2)
    {
        if(s1.size()!=s2.size()+1) return false;
        int i=0,j=0;
        while(i<s1.size())
        {
            if(j<s2.size() && s1[i]==s2[j])
            {
                i++,j++;
            }
            else i++;
        }
        if(i==s1.size() && j==s2.size()) return true;
        else return false;
    }

    static bool comp(string &s1,string&s2)
    {
        return s1.size()<s2.size();
    }

    int longestStrChain(vector<string>& words) {
        // Time  : O(n² × L)
        // Space : O(n)
        int n=words.size();
        //sorting is imp as qs demand is subset not subseq/substring
        // Sort by length so that every possible predecessor
        // is processed before the current word
        sort(words.begin(),words.end(),comp);
        //Now just find length of LIS
        vector<int> dp(n,1);
        int maxi=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(check(words[i],words[j]) && (1+dp[j]>dp[i]))
                {
                    dp[i]=1+dp[j];
                }
            }
            if(maxi<dp[i])
            maxi=dp[i];
        }


        return maxi;
    }
};