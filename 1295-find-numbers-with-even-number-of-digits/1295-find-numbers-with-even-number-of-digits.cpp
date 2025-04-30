class Solution {
public:
    int findNumbers(vector<int>& nums) 
    {
        int count{};

        for(int num : nums)
        {
            if(countNumDigits(num) % 2 == 0)
            {
                ++count;
            }
        }

        return count;
    }

    int countNumDigits(int num)
    {
        int count{};

        while(num > 0)
        {
            ++count;
            num /= 10;
        }

        return count;
    }
};