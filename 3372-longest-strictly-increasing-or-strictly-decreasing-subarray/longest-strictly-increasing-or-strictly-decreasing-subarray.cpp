class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // TC: O(N)
        // SC: O(1)

        int n = nums.size();

        // ans1 = Longest strictly increasing subarray
        // ans2 = Longest strictly decreasing subarray
        int ans1 = 1, ans2 = 1;

        int i = 0, j = 1;

        // 1. Find longest strictly increasing subarray
        // i = start index of current increasing subarray
        // j = current index being checked
        while (j < n) {
            if (nums[j] > nums[j - 1]) {
                // Increasing condition satisfied
                // Current length = j - i + 1
                ans1 = max(ans1, j - i + 1);
            }
            else {
                // Break in increasing sequence
                // Start a new subarray from j
                i = j;
            }
            j++;
        }

        i = 0, j = 1;

        // 2. Find longest strictly decreasing subarray
        while (j < n) {
            if (nums[j] < nums[j - 1]) {
                // Decreasing condition satisfied
                ans2 = max(ans2, j - i + 1);
            }
            else {
                // Break in decreasing sequence
                // Start a new subarray from j
                i = j;
            }
            j++;
        }

        // Answer = maximum of increasing and decreasing lengths
        return max(ans1, ans2);
    }
};