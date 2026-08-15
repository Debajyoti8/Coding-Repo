class Solution {
public:

    int numDistinct(string s, string t) {
        //Space opt 1-based idx to avoid neg indexing
        //using 1 1D array
        //tc-O(nm)
        //sc-O(m)
        int n=s.size();
        int m=t.size();
        vector<double> prev(m+1,0);

        //base cases
        prev[0]=1;  //0th idx elem will always be 1
        //2nd base case already covered due to initialising with 0
        
        //use nested loops 
        for(int i=1;i<=n;i++) //i=0 base case already covered
        {
            for(int j=m;j>=1;j--)
            {
                //explore all possibilities               
                    if(s[i-1]==t[j-1])
                    prev[j]= prev[j-1]+prev[j];                               
            }
        }

        return (int)prev[m]; //typecasted to int
    }
};