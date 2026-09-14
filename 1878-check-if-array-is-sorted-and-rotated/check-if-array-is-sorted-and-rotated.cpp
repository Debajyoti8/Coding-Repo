class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        // Count places where increasing order breaks
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > nums[(i + 1) % n])
                cnt++;
        }

        // Sorted rotated array can have at most one break
        return cnt <= 1;
    }
};