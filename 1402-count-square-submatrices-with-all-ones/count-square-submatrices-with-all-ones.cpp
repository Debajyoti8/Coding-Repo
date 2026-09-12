class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // Time: O(n × m)
        // Space: O(n × m) because of the 2D dp table.
        int n = matrix.size();
        int m = matrix[0].size();

        // dp[i][j] = largest square of 1s
        // having (i,j) as its bottom-right corner
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // First row and first column can only form 1x1 squares
        for(int j = 0; j < m; j++)
            dp[0][j] = matrix[0][j];

        for(int i = 0; i < n; i++)
            dp[i][0] = matrix[i][0];

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(matrix[i][j] == 0)
                    dp[i][j] = 0;
                else
                {
                    // Current cell can extend a square
                    // only if top, left and diagonal support it
                    dp[i][j] = 1 + min({
                        dp[i-1][j],
                        dp[i][j-1],
                        dp[i-1][j-1]
                    });
                }
            }
        }

        // dp[i][j] tells how many squares end at (i,j)
        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                sum += dp[i][j];
        }

        return sum;
    }
};