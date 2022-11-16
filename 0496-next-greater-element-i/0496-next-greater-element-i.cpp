class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n^2)
    * Space Complexity : O(1)
    */
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> result;
        for(int i =  0 ; i < (int)nums1.size() ; i++)
        {
            bool foundElem{}, foundGreater{};
            for(int j = 0 ; j < (int)nums2.size() ; j++)
            {
                if(nums1[i] == nums2[j])
                    foundElem = 1;
                
                if(foundElem && nums2[j] > nums1[i])
                {
                    result.push_back(nums2[j]);
                    foundGreater = 1;
                    break;
                }
                    
            }
            if(!foundGreater)
                result.push_back(-1);
        }
        return result;
    }
};