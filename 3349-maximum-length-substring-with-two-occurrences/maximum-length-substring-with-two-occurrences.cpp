class Solution {
public:
    int maximumLengthSubstring(string s) {
        //Time: O(n²)
        // Space: O(26) = O(1)
        int n=s.size();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            //vecftor inside nhi huwa toh reset nhi hoga count
            vector<int> cnt(26, 0);

            for (int j = i; j < n; j++) {
                cnt[s[j] - 'a']++;

                if (cnt[s[j] - 'a'] > 2)
                    break; //check for next i

                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};