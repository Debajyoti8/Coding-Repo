class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // j → zero ki position jahan non-zero ko bhejna hai
        // i → aage non-zero search karta hai
        int n=nums.size();
        // Pointer to the first zero
        int j=-1;
        
        // Find the first zero
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        // If no zero found, return
        if (j == -1) return;

        // Start from the next index of first zero
        for (int i = j + 1; i < nums.size(); i++) {
            // If current element is non-zero
            if (nums[i] != 0) {
                // Swap with nums[j]
                swap(nums[i], nums[j]);
                // Move j to next zero
                j++;
            }
        }
    }
};