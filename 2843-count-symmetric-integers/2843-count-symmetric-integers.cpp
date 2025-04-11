class Solution {
public:
    int countSymmetricIntegers(int low, int high) 
    {
        int count{};
        
        for(int i = low ; i <= high ; ++i)
        {
            count += isSymmetricInteger(i);
        }

        return count;
    }

    bool isSymmetricInteger(int val)
    {
        vector<int> digits;
        while(val > 0)
        {
            digits.push_back(val % 10);
            val /= 10;
        }

        int len = digits.size();
        if(len&1)
            return false;
        
        int leftSum = accumulate(digits.begin(), digits.begin() + len / 2, 0);
        int rightSum = accumulate(digits.begin() + len / 2, digits.end(), 0);

        return leftSum == rightSum;
    }
};