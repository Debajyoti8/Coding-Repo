class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Better approach
        // TC: O(n) average
        // SC: O(n)
        // Works with negative numbers too

        int n = nums.size();
        unordered_map<long long, int> mp;

        for(int i = 0; i < n; i++)
        {
            long long rem = target - nums[i];
            // Agar insertion pehle kar diya?Same element ko do baar use kar liya.
            if(mp.find(rem) != mp.end())
                return {i, mp[rem]};
            else
                mp[nums[i]] = i;
        }

        return {};
    }
};