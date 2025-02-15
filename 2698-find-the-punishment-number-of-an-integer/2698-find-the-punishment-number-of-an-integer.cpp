class Solution {
public:
    int punishmentNumber(int n) 
    {
        int result{};
        for(int i = 1 ; i <= n ; ++i)
        {
            int num = i*i;
            bool isPunishmentNum = false;
            isPunishment(to_string(num), i, 0, 0, isPunishmentNum);
            if(isPunishmentNum)
                result += num;
        }

        return result;
    }

    void isPunishment(string numSquared, int num, int curSum, int idx, bool& isPunishmentNum)
    {
        if(idx == numSquared.size())
            isPunishmentNum |= (curSum == num);

        if(idx > numSquared.size() || num < curSum || isPunishmentNum)
            return;

        string curStr{};
        for(int i = idx ; i < numSquared.size() ; ++i)
        {
            curStr += numSquared[i];
            isPunishment(numSquared, num, curSum + stoi(curStr), i+1, isPunishmentNum);
        }
    }
};