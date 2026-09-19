class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> pos, neg, ans(n);

        for(int x : nums) {
            if(x > 0) pos.push_back(x);
            else neg.push_back(x);
        }

        int p = 0, q = 0;

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0)
                ans[i] = pos[p++];
            else
                ans[i] = neg[q++];
        }

        return ans;
    }
};