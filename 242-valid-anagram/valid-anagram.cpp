class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) return false;

        int n = s.length();

        map<char, int> a, b;

        for (int i = 0; i < n; i++) { 
            a[s[i]]++;
            b[t[i]]++;
        }
        
        for (char c = 'a';c<='z';c++)
            if (a[c] != b[c]) return false;
        
        return true;
    }
};