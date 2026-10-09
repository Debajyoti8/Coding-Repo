class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // TC-O(nm)
        // SC-O(1)
        vector<int> ans;
        vector<bool> visited(1001,0);

        for(int value:nums1)
        {
            for(int i=0;i<nums2.size();i++)
            {
                if(nums2[i]==value && !visited[nums2[i]])
                {
                    ans.push_back(value);
                    visited[nums2[i]]=1;
                    break;
                }
            }
        }
            return ans;
    }
};