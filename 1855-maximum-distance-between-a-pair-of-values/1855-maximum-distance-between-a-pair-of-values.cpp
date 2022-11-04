class Solution {
public:
    /* 
    * Approach:
    * binary search
    * 
    * Complexity:
    * Time Complexity : O(mlogn)
    * Space Complexity : O(1)
    */
    int maxDistance(vector<int>& nums1, vector<int>& nums2) 
    {
        int maxDistance{};
        
        for(int i = 0 ; i < (int)nums1.size() ; i++)
        {
            auto lb = lower_bound(nums2.rbegin() , nums2.rend(), nums1[i]);
            
            int lbIdx = nums2.rend() - lb - 1;
            if(lbIdx >= i)
                maxDistance = max(maxDistance, lbIdx - i);
        }
        
        return maxDistance;
    }
};