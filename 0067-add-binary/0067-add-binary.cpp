class Solution {
public:
    /* 
    * Approach:
    * Complexity:
    * Time Complexity : O(max(a.length, b.length))
    * Space Complexity : O(1) >> neglecting the output space
    */
    string addBinary(string a, string b) 
    {
        string result{};
        int itr1{(int)a.size()-1}, itr2{(int)b.size()-1}, carry{};;
        
        while(itr1 >= 0 || itr2 >= 0 || carry)
        {
            int sum = carry;
            
            if(itr1 >= 0)
                sum += a[itr1--] - '0';
            if(itr2 >= 0)
                sum += b[itr2--] - '0';
            
            result = to_string(sum%2) + result , carry = sum/2;
        }
        
        return result;
    }
};