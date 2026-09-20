class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //STl function
        // TC: O(n)
        // SC: O(1)
        next_permutation(nums.begin(),nums.end());
    }
};