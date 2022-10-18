class Solution {
public:
    /* 
    * Approach:
    * Iterate over the input array and store each number with its frequency in
    * hashmap, then find the majority element with frequency > n/2
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int, int> um;
        
        for(int n : nums)
            um[n]++;
        
        for(auto [num, count] : um)
            if(count > (int)nums.size()/2)
                return num;
        
        return 0;
    }
};