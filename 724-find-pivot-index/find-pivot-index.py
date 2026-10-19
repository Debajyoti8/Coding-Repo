class Solution:
    def pivotIndex(self, nums: list[int]) -> int:
        n=len(nums)
        total=sum(nums)
        leftSum=0

        for i in range(n):
            rightSum=total-leftSum-nums[i]
            if rightSum==leftSum:
                return i
            else:
                leftSum+=nums[i]

        return -1;    