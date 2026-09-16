class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Empty space end mein hai → largest element choose karo → end se fill karo.
        // Time: O(m+n)
// Space: O(1)
        // i -> last actual element of nums1
        // j -> last element of nums2
        // k -> last position of nums1

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        // nums2 is the only array that must be completely processed
        while(j >= 0) {
            if(i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            }
            else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};