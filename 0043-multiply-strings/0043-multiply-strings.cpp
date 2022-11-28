class Solution {
public:
    string multiply(string num1, string num2) 
    {
        // always make num1 the smaller string
        if(num2.size() < num1.size())
            return multiply(num2, num1);
        
        string result{"0"};
        int cnt{};
        
        for(int i = (int)num1.size()-1 ; i >= 0 ; i--)
        {
            string multiplication = mulOneDigit(num2, num1[i]-'0');
            
            for(int j = 0 ; j < cnt ; j++)
                multiplication += "0";
            
            result = addStrings(result, multiplication);
            cnt++;
        }
        
        return result;
    }
    
    string mulOneDigit(string num, int digit)
    {
        if(!digit)
            return "0";
        
        int carry{}, itr{(int)num.size() - 1};
        string res{};
        while (itr >= 0 || carry)
        {
            int m{};

            if (itr >= 0)
                m += (num[itr--] - '0');

            m *= digit;
            m += carry;

            res = to_string(m % 10) + res;
            carry = m / 10;
        }
        return res;
    }
    
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