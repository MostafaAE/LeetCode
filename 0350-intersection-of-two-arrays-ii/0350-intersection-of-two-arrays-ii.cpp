class Solution {
public:
    
    /* Approach: 
     * use unordered_map to store the values and their count of one array
     * iterate on ther other array and check if element exist in the hashmap and its count > 0
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(n)
     */

    
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> ump;
        vector<int> result;
        for(int i = 0 ; i < (int)nums1.size() ; i++)
        {
            if(ump.count(nums1[i]))
                ump[nums1[i]]++;
            else
                ump[nums1[i]]= 1;
        }
        
        for(int i = 0 ; i < (int)nums2.size() ; i++)
        {
            if(ump.count(nums2[i]) && ump[nums2[i]] > 0)
            {
                ump[nums2[i]]--;
                result.push_back(nums2[i]);
            }
        }
        return result;
        
    }
};