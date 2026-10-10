class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Better approach
        // TC: O(n) average
        // SC: O(n)
        // Works with negative numbers too

        int n = numbers.size();
        unordered_map<long long, int> mp;

        for(int i = 0; i < n; i++)
        {
            long long rem = target - numbers[i];
            // Agar insertion pehle kar diya?Same element ko do baar use kar liya.
            if(mp.find(rem) != mp.end())
                return {mp[rem]+1,i+1};
            else
                mp[numbers[i]] = i;
        }

        return {};
    }
};