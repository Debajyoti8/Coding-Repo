class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();

        vector<long long> preL(n + 1, 0);
        vector<long long> preLC(n + 1, 0);

        long long l = 0, lc = 0, countLCT = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                l++;
            }
            else if (s[i] == 'C') {
                lc += l;
            }
            else if (s[i] == 'T') {
                countLCT += lc;
            }

            preL[i] = l;
            preLC[i] = lc;
        }

        vector<long long> sufT(n + 1, 0);
        vector<long long> sufCT(n + 1, 0);

        long long t = 0, ct = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'T') {
                t++;
            }
            else if (s[i] == 'C') {
                ct += t;
            }

            sufT[i] = t;
            sufCT[i] = ct;
        }

        long long answer1 = sufCT[0] + countLCT;
        long long answer2 = preLC[n - 1] + countLCT;

        long long answer3 = 0;

        for (int i = 0; i < n; i++) {
            long long curr = preL[i] * sufT[i + 1];
            answer3 = max(answer3, curr);
        }

        return max({answer1, answer2, answer3 + countLCT});
    }
};