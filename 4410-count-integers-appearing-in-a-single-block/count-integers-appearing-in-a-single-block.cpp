class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        // Time = O(n)
        // Space = O(1)
        int n = nums.size();

        // first[x] = x ki first occurrence ka index
        // last[x] = x ki last occurrence ka index
        vector<int> first(101, -1);
        vector<int> last(101, -1);

        // First aur last occurrence store karo
        for(int i = 0; i < n; i++)
        {
            if(first[nums[i]] == -1)
                first[nums[i]] = i;

            last[nums[i]] = i;
        }

        int ans = 0;

        // Har distinct number ko check karo
        for(int x = 1; x <= 100; x++)
        {
            if(first[x] == -1)
                continue;

            bool special = true;

            // First se last occurrence ke beech
            // agar koi different number mila,
            // toh x multiple blocks mein hai
            for(int i = first[x]; i <= last[x]; i++)
            {
                if(nums[i] != x)
                {
                    special = false;
                    break;
                }
            }

            if(special)
                ans++;
        }

        return ans;
    }
};