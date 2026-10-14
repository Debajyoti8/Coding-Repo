
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // TC: O(n) average — each character enters and leaves the window at most once
        // Auxiliary SC: O(min(n, alphabet size)) — frequency map

        int n = s.size();
        unordered_map<char, int> mp;
        int maxi = 0;
        int low = 0;

        for (int high = 0; high < n; high++) {
            mp[s[high]]++; // Expand window by adding the current character

            // Shrink window while the current character is repeated
            while (mp[s[high]] > 1) {
                mp[s[low]]--; // Remove the leftmost character's frequency
                low++;        // Move left boundary forward
            }

            // Window now contains no repeating characters
            maxi = max(maxi, high - low + 1);
        }

        return maxi; // Length of the longest substring without repetition
    }
};
