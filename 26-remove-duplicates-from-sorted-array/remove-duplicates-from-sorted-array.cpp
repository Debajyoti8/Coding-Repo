class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        int i = 0;  // i = last index of unique elements

        for(int j = 1; j < n; j++) {
            // If a new unique element is found
            if(nums[j] != nums[i]) {
                nums[i + 1] = nums[j];  // Place it after unique portion
                i++;
            }
        }

        // First i+1 elements contain all unique elements
        return i + 1;
    }
};