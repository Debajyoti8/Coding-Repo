
class Solution {
public:
    int firstUniqChar(string s) {
        // TC: O(N) average | SC: O(26)

        unordered_map<char, int> freq;

        // Step 1: Count frequency of every character
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Traverse ORIGINAL STRING to maintain order
        // Do not traverse unordered_map because it does not maintain order
        for (int i = 0; i < s.size(); i++) {

            // Check whether the current character occurs only once
            if (freq[s[i]] == 1) {
                return i;  // First unique character found
            }
        }

        // No unique character exists
        return -1;
    }
};
