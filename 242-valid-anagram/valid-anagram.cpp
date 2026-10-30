
class Solution {
public:
    bool isAnagram(string s, string t) {
        // TC: O(N log N) | SC: O(1) auxiliary space (excluding sorting implementation)
        
        if (s.size() != t.size()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};
