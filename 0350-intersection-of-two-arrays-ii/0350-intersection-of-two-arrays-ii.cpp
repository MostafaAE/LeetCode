class Solution {
public:
    
    /* Approach: 
     * use unordered_map to store the values and their count of one array
     * iterate on ther other array and check if element exist in the hashmap and its count > 0
     *
     * Complexity:
     * Time Complexity : O(n+m)
     * Space Complexity : O(min(n,m))
     */
    
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        // What if nums1's size is small compared to nums2's size? Which algorithm is better?
        // Swap nums1 and nums2 to make nums1 always smaller for minimum space complexity
        if((int)nums1.size() > (int)nums2.size())
            return intersect(nums2, nums1);
            
        unordered_map<int, int> ump;
        vector<int> result;
        
        for(int i = 0 ; i < (int)nums1.size() ; i++)
            ump[nums1[i]]++;
        
        for(int i = 0 ; i < (int)nums2.size() ; i++)
            if(ump.count(nums2[i]) && ump[nums2[i]] > 0)
                ump[nums2[i]]--,result.push_back(nums2[i]);
        
        return result;
    }
};