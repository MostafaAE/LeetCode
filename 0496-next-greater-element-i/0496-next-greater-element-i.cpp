class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n^2)
    * Space Complexity : O(1) >> neglecting the output space
    */
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> result((int)nums1.size(), -1);
        
        for(int i =  0 ; i < (int)nums1.size() ; i++)
        {
            bool foundElem{};
            for(int j = 0 ; j < (int)nums2.size() ; j++)
            {
                if(nums1[i] == nums2[j])
                    foundElem = 1;
                
                if(foundElem && nums2[j] > nums1[i])
                {
                    result[i] = nums2[j];
                    break;
                }
            }
        }
        return result;
    }
};