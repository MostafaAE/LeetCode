class Solution {
public:
    /* 
    * Approach: 
    * To get the maximum odd binary number we have to arrange the bits so that there is 1 in the right most bit and the rest of 1s are in the left most bits.
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    string maximumOddBinaryNumber(string s) 
    {
        int n{(int)s.size()}, left{-1};
        
        for(int i = 0 ; i < n ; i++)
            if(s[i] == '1')
                swap(s[i], s[++left]);
        
        swap(s[left], s[n-1]);
        
        return s;
    }
};