class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // TC: O(n)
        // SC: O(n)
        // optimized one-pass monotonic stack approach.
        // For every index i:
        // push → at most once
        // pop  → at most once

        int n = heights.size();
        stack<int> st;
        int maxA = 0;

        // Monotonic increasing stack of indices
        // When current height is smaller, calculate area
        for(int i = 0; i <= n; i++)
        {
            // i == n acts as a sentinel (height = 0)
            // It forces all remaining bars to be popped
            while(!st.empty() &&
                  (i == n || heights[st.top()] >= heights[i]))
            {
                // Current popped bar is the minimum height
                int hght = heights[st.top()];
                st.pop();

                // Find the maximum width possible for this height
                int width;

                if(st.empty())
                    width = i;              // Rectangle starts from index 0
                else
                    width = i - st.top() - 1; // Between two smaller bars

                // Area = height × width
                maxA = max(maxA, width * hght);
            }

            // Don't push sentinel index n
            if(i < n)
                st.push(i);
        }

        return maxA;
    }
};