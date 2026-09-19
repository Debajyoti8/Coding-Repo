class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Kadane Algo (Prefix Sum )
        // TC: O(n)
        // SC: O(1)

        long long prefix = 0, maxi = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            // Current subarray ka sum maintain karo
            prefix += nums[i];

            // Ab tak ka maximum subarray sum
            maxi = max(maxi, prefix);

            // Negative sum future answer ko reduce karega,
            // isliye new subarray yahin se start karo
            if(prefix < 0)
                prefix = 0;
        }

        return maxi;
    }
};