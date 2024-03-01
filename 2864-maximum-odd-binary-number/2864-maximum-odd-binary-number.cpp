class Solution {
public:
    /* 
    * Approach: 
    * To get the maximum odd binary number we have to arrange the bits so that there is 1 in the right most bit and the rest of 1s are in the left most bits.
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1) => ignoring output space
    */
    string maximumOddBinaryNumber(string s) 
    {
        int n{(int)s.size()};
        string result = string(n, '0');
        result[n-1] = '1';
        
        int idx1 = s.find("1") + 1, idx2{};
        while(idx1 < n)
            if(s[idx1++] == '1')
                result[idx2++] = '1';
        
        return result;
    }
};