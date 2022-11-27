class Solution {
public:
    /* 
    * Approach:
    * Simulating binary addition
    *
    * Complexity:
    * Time Complexity : O(max(a.length, b.length))
    * Space Complexity : O(1) >> neglecting the output space
    */
    string addBinary(string a, string b) 
    {
        int carry{}, aItr{(int)a.size()-1}, bItr{(int)b.size()-1};
        string result{};
        
        while(aItr >= 0 || bItr >= 0 || carry)
        {
            int sum = carry;
            
            if(aItr >= 0)
                sum += a[aItr--] - '0';
            if(bItr >= 0)
                sum += b[bItr--] - '0';
            
            result = to_string(sum%2) + result;
            carry = sum / 2;
        }
        
        return result;
    }
};