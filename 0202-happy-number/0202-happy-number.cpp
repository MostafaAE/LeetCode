class Solution {
public:
    bool isHappy(int n) 
    {
        while(n > 9)
        {
            int digitsSum{};
            while(n)
            {
                int d = n%10;
                digitsSum += d*d;
                n/=10;
            }
            n = digitsSum;
        }
        
        if(n == 7 || n == 1)
            return true;
        return false;
    }
};