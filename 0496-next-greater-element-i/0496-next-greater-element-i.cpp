class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(m+n)
    * Space Complexity : O(m)
    */
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> valToIdx;
        stack<int> s;
        vector<int> result((int)nums1.size(), -1);
        
        for(int i = 0 ; i < (int)nums1.size() ; i++)
            valToIdx[nums1[i]] = i;
        
        for(int i = 0 ; i < (int)nums2.size() ; i++)
        {
            while(!s.empty() && nums2[i] > s.top())
                result[valToIdx[s.top()]] = nums2[i], s.pop();
            
            if(valToIdx.count(nums2[i]))
                s.push(nums2[i]);
        }
        
        return result;
    }
};