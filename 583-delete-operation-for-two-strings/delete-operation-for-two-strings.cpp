class Solution {
public:

    int lcs(string &s, string &t)
    {
        int n = s.size();
        int m = t.size();

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


    int minDistance(string word1, string word2) {
        //space opt
        //Time Complexity  : O(n × m)
        // Space Complexity : O( m)
        int n=word1.size();
        int m=word2.size();

        return n+m-2*lcs(word1,word2);
    }
};