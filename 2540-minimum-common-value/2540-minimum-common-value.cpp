class Solution {
public:
    /* 
    * Approach:
    * Two pointers approach.
    * 
    * Complexity:
    * Time Complexity : O(n + m)
    * Space Complexity : O(1)
    */
    int getCommon(vector<int>& nums1, vector<int>& nums2) 
    {
        int sz1{(int)nums1.size()}, sz2{(int)nums2.size()};
        int itr1{}, itr2{};
        
        while(itr1 < sz1 && itr2 < sz2)
        {
            if(nums1[itr1] == nums2[itr2])
                return nums1[itr1];
            else if(nums1[itr1] < nums2[itr2])
                itr1++;
            else
                itr2++;
        }
        
        return -1;
    }
};