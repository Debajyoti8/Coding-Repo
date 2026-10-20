class Solution:
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        n = len(nums)
        windowSum = sum(nums[:k])
        ans = windowSum / k

        i, j = 0, k

        while j < n:
            windowSum += nums[j]
            windowSum -= nums[i]

            avg = windowSum / k
            ans = max(ans, avg)

            i += 1
            j += 1

        return ans