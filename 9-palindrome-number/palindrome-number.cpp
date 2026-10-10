class Solution {
public:
    bool isPalindrome(int x) {
        // TC-O(log10x)
        // SC-O(1)
        if (x < 0) return false;

        long long ans = 0;
        int temp = x;

        while (temp > 0) {
            int rem = temp % 10;
            ans = ans * 10 + rem;
            temp /= 10;
        }

        return ans == x;
    }
};
