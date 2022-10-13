class Solution {
public:
    /* Approach: 
     * use unordered_set to store the values of each array (remove duplicates)
     * iterate on one unordered_set and check each element if it exists in the other unordered_set
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(n)
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> s1, s2;
        vector<int> result;
        
        for(int i = 0 ; i < (int)nums1.size() ; i++)
            s1.insert(nums1[i]);
        
        for(int i = 0 ; i < (int)nums2.size() ; i++)
            s2.insert(nums2[i]);
        
        for(int elem : s2)
            if(!s1.insert(elem).second)
                result.push_back(elem);
        
        return result;
    }
};