class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(max(L1, L2))
    * Space Complexity : O(L1 + L2) where L1 is num1.length, L2 is num2.length
    */
    string addStrings(string num1, string num2) 
    {
        int carry{}, itr1{(int)num1.size() - 1}, itr2{(int)num2.size() - 1};
        string res;

        while (itr1 >= 0 || itr2 >= 0 || carry)
        {
            int sum = carry;

            if (itr1 >= 0)
                sum += (num1[itr1--] - '0');

            if (itr2 >= 0)
                sum += (num2[itr2--] - '0');

            res = to_string(sum % 10) + res;
            carry = sum / 10;
        }

        return res;
    }
};