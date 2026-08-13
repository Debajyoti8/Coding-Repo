class Solution {
public:

    int lcs(string &s, string &t)
    {
        int n = s.size(), m = t.size();

        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i - 1] == t[j - 1])
                    cur[j] = 1 + prev[j - 1];
                else
                    cur[j] = max(prev[j], cur[j - 1]);
            }
            prev = cur;
        }

        return prev[m];
    }

    int minInsertions(string s) {
        //tabulation
        //Time  = O(n²)
        //Space : O(n)
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());

        //we are doing total length - max lps
        return n-lcs(s,t); //total mai se max lps (-) krnese min insertions milega
    }
};