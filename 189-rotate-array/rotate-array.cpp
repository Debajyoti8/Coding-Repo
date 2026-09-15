class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Time: O(n)
        // Space: O(1) auxiliary space

        int n = nums.size();
        k = k % n;

        // Reverse first n-k elements
        reverse(nums.begin(), nums.begin() + (n-k));

        // Reverse last k elements
        reverse(nums.begin() + (n-k), nums.end());

        // Reverse the entire array
        reverse(nums.begin(), nums.end());
    }
};