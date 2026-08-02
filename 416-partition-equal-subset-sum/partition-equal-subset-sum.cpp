class Solution {
public:

    bool canPartition(vector<int>& arr) {
        //Space
        //2d->1d
        //Time: O(n*sum)
        // Space: O(sum)
        int n=arr.size();
        int totalsum=0;
        for(auto x:arr) totalsum+=x;
        if(totalsum%2==1) return false;

        int sum=totalsum/2;
        vector<bool> prev(sum+1,0);
        
        //base cases
        prev[0]=1;   //index 0 and sum 0 ho gaya 
        
        if(arr[0] <= sum)
            prev[arr[0]] = true;  //at index 0 if there is taregt of a[0]
        
        //form nested loops and fill dp table
        for(int i=1;i<n;i++)
        {
            vector<bool> curr(sum+1,0);
            curr[0] = true;
            for(int j=1;j<=sum;j++)
            {
                //copy recurrence
                 bool take=0;
                if(arr[i]<=j)
                take= prev[j-arr[i]];
                
                bool nottake=prev[j];
                
                curr[j]=take || nottake;
            }
            prev=curr;
        }
        
        
            
        
        return prev[sum];
        
    }
};