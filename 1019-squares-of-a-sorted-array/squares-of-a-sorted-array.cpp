class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // TC: O(n) — single traversal using two pointers
        // SC: O(1) auxiliary space, O(n) including output
        int n=nums.size();
        vector<int> ans(n);
        int l=0,r=n-1;
        for(int i=n-1;i>=0;i--)
        {
            if(abs(nums[l]) > abs(nums[r]))
            {
                ans[i] = nums[l] * nums[l++];
            }
            else 
                ans[i] = nums[r] * nums[r--];
        }

        return ans;
    }
};