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
        int carry{1};
        
        for(int i = size -1 ; i >= 0 ; i--)
        {
            digits[i] += carry;
            
            if(digits[i] == 10)
                digits[i] = 0, carry = 1;
            else
                carry = 0;
        }
        
        if(carry)
            digits.push_back(0), digits[0] = 1;
        
        return digits;
    }
};