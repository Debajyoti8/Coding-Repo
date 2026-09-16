class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        vector<int> temp;
        //both array present
        while(i<m && j<n)
        {
            if(nums1[i]>nums2[j])
            {
                temp.push_back(nums2[j]);
                j++;
            }
            else
            {
                temp.push_back(nums1[i]);
                i++;    
            }
        }
        //only nums2 present
        while(j<n)
        {
            temp.push_back(nums2[j]);
            j++;
        }
        //only nums1 present
        while(i<m)
        {
            temp.push_back(nums1[i]);
            i++;
        }

        nums1 = temp;
        
    }

};