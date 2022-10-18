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
        
        while(digitsNum > 1)
        {
            // extract leftmost digit
            int leftDigitTens = pow(10, digitsNum-1);
            int leftDigit = x / leftDigitTens;
            
            // extract rightmost digit
            int rightDigit = x % 10;
            
            if(leftDigit != rightDigit)
                return false;
            
            // drop the leftmost and rightmost digits from the number
            x = (x - leftDigit*leftDigitTens)/10;
            digitsNum-=2;
        }
        
        return true;
        
    }
};