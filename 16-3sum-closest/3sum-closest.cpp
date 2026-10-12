
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = nums[0] + nums[1] + nums[2];
        long long mini = LLONG_MAX;

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                long long sum = (long long)nums[i] + nums[l] + nums[r];
                long long diff = abs(sum - (long long)target);

                // Update the closest sum found so far
                if (diff < mini) {
                    mini = diff;
                    ans = (int)sum;
                }

                // Exact match: no better answer is possible
                if (sum == target) {
                    return (int)sum;
                }
                else if (sum < target) {
                    l++;  // Increase the sum
                }
                else {
                    r--;  // Decrease the sum
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
- Two-pointer traversal: O(n) per iteration
- Overall: O(n^2)

Auxiliary Space: O(log n) typically
- Used by sorting recursion/implementation.

Output Space: O(1)
- Only a few variables are used.
*/
