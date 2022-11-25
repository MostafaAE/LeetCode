class Solution {
public:
    /* 
    * Approach:
    * Get the number of digits in the input number, keep extracting and comparing
    * then dropping the leftmost and rightmost digits from the input until
    * the number of digits become <= 1
    * 
    * Complexity:
    * Time Complexity : O(n) where n is the number of digits in the input
    * Space Complexity : O(1)
    */
    bool isPalindrome(int x) 
    {
        if(x < 0)
            return false;
        if (x == 0)
            return true;
        
        int digitsNum = log10(x)+1;
        int divider = pow(10, digitsNum-1);
        
        while(x)
        {
            // extract leftmost digit
            int leftDigit = x / divider;
            
            // extract rightmost digit
            int rightDigit = x % 10;
            
            if(leftDigit != rightDigit)
                return false;
            
            // drop the leftmost and rightmost digits from the number
            x = (x % divider) / 10;
            
            divider/=100;
        }
        
        return true;
        
    }
};