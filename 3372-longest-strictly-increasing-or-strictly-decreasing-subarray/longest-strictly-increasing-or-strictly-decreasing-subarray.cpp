class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
//         up ->	Length of increasing subarray ending at current index
// down->	Length of decreasing subarray ending at current index
// best->	Maximum length found so far
        int best = 1, up = 1, down = 1;
        for (int i = 1; i < nums.size(); ++i) {
            up = nums[i - 1] < nums[i] ? up + 1 : 1;  // increasing streak ending at nums[i]
            down = nums[i - 1] > nums[i] ? down + 1 : 1;  // decreasing streak ending at nums[i]
            best = max({best, up, down});
        }
        return best;
    }
};