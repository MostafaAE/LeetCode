class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    vector<int> plusOne(vector<int>& digits) 
    {
        int size = (int)digits.size();
        
        for(int i = size -1 ; i >= 0 ; i--)
        {
            digits[i]++;
            
            if(digits[i] <= 9)
                return digits;
            else
                digits[i] = 0;
        }
        
        digits.push_back(0);
        digits[0] = 1;
        
        return digits;
    }
};