
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // TC: O(n) — each element enters and leaves the window at most once
        // Auxiliary SC: O(1) — only constant extra variables are used

        int n = nums.size();
        int low = 0, high = 0;
        int ans = INT_MAX;
        long long sum = 0;

        while (high < n) {
            sum += nums[high]; // Expand window by adding the new element

            // Shrink window while sum >= target
            while (sum >= target) {
                ans = min(ans, high - low + 1); // Update minimum window length

                sum -= nums[low]; // Remove the leftmost element
                low++;            // Shrink window from the left
            }

            high++; // Move right pointer to expand the window
        }

        return ans == INT_MAX ? 0 : ans; // Return 0 if no valid subarray exists
    }
};
