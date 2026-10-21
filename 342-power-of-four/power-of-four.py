class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        # TC: O(log_4 n)
        # SC: O(1)
        if n <= 0:
            return False

        while n % 4 == 0:
            n //= 4

        return n == 1

