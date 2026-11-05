class Solution {
public:
    int search(vector<int>& nums, int target) {
        // TC: O(log N)
        // SC: O(1)

        int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return mid;

            // Left half is sorted
            if (nums[l] <= nums[mid]) {

                // Target lies inside sorted left half
                if (target >= nums[l] && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }

            // Right half is sorted
            else {

                // Target lies inside sorted right half
                if (target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }

        return -1;
    }
};