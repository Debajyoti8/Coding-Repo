class Solution:

    def isAlpha(self,s,i):
        # a-z or 0-9
        x=ord(s[i])
        if 97<=x<=122 or 48<=x<=57:
            return True
        else:
            return False

    def isPalindrome(self, s: str) -> bool:
#         Time complexity: \(O(n)\), because each pointer moves across the string at most once.
# Auxiliary space: \(O(1)\) for the pointers and comparisons, excluding the lowercase string copy. Since s.lower() creates a new string in the general case, the total space including that copy is (O(n)).
       s=s.lower()
       n=len(s)       

       i,j=0,n-1
       while i<j:
            if not self.isAlpha(s,i):
                i+=1
                continue
            if not self.isAlpha(s,j):
                j-=1
                continue    
            if s[i]==s[j]:
                i+=1
                j-=1
            else:
                return False 

       return True