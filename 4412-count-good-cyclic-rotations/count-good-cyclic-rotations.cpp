class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        int cnt = 0;

        long long pre = 0, sum = 0;

        // Calculate total sum of the entire array
        // We can get the other half's sum as: sum - pre
        for(int x : nums)
            sum += x;

        // Sliding window of size n/2
        // We only need to check n/2 windows because
        // the opposite rotation contains the two halves swapped.
        for(int i = 0; i < n; i++)
        {
            // Once i >= n/2, we have a complete window
            // of size n/2 stored in 'pre'.
            if(i >= n / 2)
            {
                // pre = sum of first half
                // sum - pre = sum of second half
                //
                // If the two half sums are unequal,
                // then exactly ONE of the two opposite rotations
                // will be a good rotation.
                if(pre != sum - pre)
                    cnt++;

                // Remove the element that is leaving the window
                // to slide the window by one position.
                pre -= nums[i - n / 2];
            }

            // Add the current element to form the next window
            pre += nums[i];
        }

        return cnt;
    }
};