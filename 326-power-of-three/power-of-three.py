class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        # TC: O(log_3(n))
        # SC: O(1)
        if n <= 0:
            return False  # Zero and negative numbers cannot be powers of 3

        while n % 3 == 0:
            n //= 3  # Repeatedly divide by 3 while divisible

        return n == 1  # True only if nothing remains except 1

