class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int arraySign(vector<int>& nums) 
    {
        int negCount{};
        
        for(int elem : nums)
        {
            if(elem == 0)
                return 0;
            else if (elem < 0)
                negCount++;
        }
        
        if(negCount&1)
            return -1;
        else
            return 1;
    }
};