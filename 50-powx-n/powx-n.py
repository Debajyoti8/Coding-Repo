class Solution:
    def findPow(self, x: float, n: int) -> float:
        # Base case: any non-zero number raised to power 0 is 1
        if n == 0:
            return 1

        # Base case: x^1 = x
        if n == 1:
            return x

        # Recursively calculate x^(n//2) only once
        a = self.findPow(x, n // 2)

        # If n is odd: x^n = x^(n//2) * x^(n//2) * x
        if n % 2 == 1:
            return a * a * x

        # If n is even: x^n = x^(n//2) * x^(n//2)
        return a * a

    def myPow(self, x: float, n: int) -> float:
        # Negative exponent: x^(-n) = 1 / x^n
        if n >= 0:
            return self.findPow(x, n)
        else:
            n *= -1  # Convert exponent to positive
            return 1 / self.findPow(x, n)

# TC: O(log |n|) — exponent is halved in every recursive call
# SC: O(log |n|) — recursion call stack