
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort to use two pointers and easily skip duplicates
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            // Skip duplicate first elements to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;  // Left pointer
            int k = n - 1;  // Right pointer

            while (j < k) {
                // Use long long to avoid overflow when summing integers
                long long sum = (long long)nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++;  // Need a larger sum
                }
                else if (sum > 0) {
                    k--;  // Need a smaller sum
                }
                else {
                    // Found a valid triplet
                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    // Skip duplicate second elements
                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    // Skip duplicate third elements
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        return ans;
    }
};

/*
Time Complexity: O(n^2)
- Sorting: O(n log n)
- Outer loop: O(n)
- Two-pointer traversal for each i: O(n)
- Overall: O(n^2)

Auxiliary Space: O(log n) typically
- Sorting uses O(log n) stack space in common implementations.
- Two pointers and sum use O(1) extra space.

Output Space: O(k), where k is the number of unique triplets.
Total Space: O(log n + k), typically.
*/
