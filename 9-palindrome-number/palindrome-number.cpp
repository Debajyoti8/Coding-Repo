class Solution {
public:
    bool isPalindrome(int x) {
        /*
Time Complexity: O(d), where d = number of digits in x.
Converting x to a string takes O(d), and the two-pointer
traversal takes O(d). Since d = O(log10(x)), TC is O(log10(x)).

Auxiliary Space: O(d) = O(log10(x)), because the string
stores all d digits of x.
*/
        if (x < 0) return false;

        string s = to_string(x);
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
};