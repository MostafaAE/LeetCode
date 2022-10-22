class Solution {
public:
    /* 
    * Approach:
    * summation math equation
    * 
    * Complexity:
    * Time Complexity : O(1)
    * Space Complexity : O(1)
    */
    int arrangeCoins(int n) 
    {
        // summation eq = k*(k+1) / 2
        // let's reverse it
        // k^2 + k + 0 <= 2n
        // by completing the square
        // k^2 + k = (k+h)^2 - d =  (k+0.5)^2 - 0.25 <= 2n
        // result = sqrt(2n + 0.25) - 0.5
        
        return (int)(sqrt(2*(long long)n + 0.25) - 0.5);
    }
};

