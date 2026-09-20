class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();

        // Find the breakpoint: first nums[i] < nums[i+1] from right
        int ind = -1;

        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // No breakpoint → already the largest permutation
        if(ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the smallest element greater than nums[ind]
        // Since suffix is decreasing, first greater from right is optimal
        for(int i = n - 1; i > ind; i--) {
            if(nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Make suffix smallest possible
        reverse(nums.begin() + ind + 1, nums.end());
    }
};