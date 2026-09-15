class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Time: O(n)
        // Space: O(k) auxiliary space
        
        int n = nums.size();
        k = k % n;

        // Store last k elements
        vector<int> temp(k);

        for(int i=n-1; i>=n-k; i--)
            temp[i-n+k] = nums[i];

        // Right shift remaining elements
        for(int i=n-1; i>=k; i--)
            nums[i] = nums[i-k];

        // Put last k elements at front
        for(int i=0; i<k; i++)
            nums[i] = temp[i];
    }
};