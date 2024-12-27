class Solution {
public:
    string convertDateToBinary(string date) 
    {
        string result{}, word{};
        stringstream ss(date);

        while(getline(ss, word, '-'))
        {
            if(!result.empty())
                result += '-';

            result += convertNumberToBinary(convertStringToNumber(word));
        }
        
        return result;
    }

    int convertStringToNumber(string str)
    {
        int result{};
        for(int i = 0 ; i < str.size() ; ++i)
            result = result * 10 + (str[i] - '0');

        return result;
    }

    string convertNumberToBinary(int num)
    {
        string result{};
        int val = 4096; // 2^12
        while(val > 0)
        {
            int bit = num / val;
            num %= val;
            val /= 2;

            if(result.empty() && bit == 0)
                continue;

            result += ('0' + bit);
        }

        return result;
    }
};