class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    int subtractProductAndSum(int n) 
    {
        int sum{}, product{1};
        
        while(n)
        {
            int digit = n % 10;
            product *= digit;
            sum += digit;
            n /= 10;
        }
        
        return product - sum;
        
    }
};