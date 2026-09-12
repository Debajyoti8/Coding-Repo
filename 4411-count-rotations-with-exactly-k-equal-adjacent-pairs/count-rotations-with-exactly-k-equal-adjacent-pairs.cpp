class Solution {
public:
    int countRotations(string s, int k) {
        // TC-> n rotations × n adjacent comparisons = O(n²)
        // SC = O(1)
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            int cnt = 0;

            // Count equal adjacent pairs
            for(int j = 0; j < n - 1; j++)
            {
                if(s[j] == s[j + 1])
                    cnt++;
            }

            if(cnt == k)
                ans++;

            // Left rotate: move first character to the end
            char ch = s[0];
            s.erase(s.begin());
            s.push_back(ch);
        }

        return ans;
    }
};