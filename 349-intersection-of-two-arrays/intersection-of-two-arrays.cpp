
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Time Complexity: O(n + m) average
//         Space Complexity: O(n) auxiliary space
// - Hash set stores at most n unique elements
// - Output vector is excluded from auxiliary space

        // Store unique elements of nums1 in a hash set
        unordered_set<int> s(nums1.begin(), nums1.end());

        vector<int> ans;

        // Traverse nums2 and find common elements
        for (int x : nums2) {
            // count(x) returns 1 if x exists, otherwise 0
            if (s.count(x)) {
                ans.push_back(x); // Add common element
                s.erase(x);       // Remove it to avoid duplicates
            }
        }

        return ans;
    }
};


