class Solution {
public:
    /* 
    * Approach:
    * simulation
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    bool lemonadeChange(vector<int>& bills) 
    {
        int fives{}, tens{};
        
        for(int i = 0 ; i < (int)bills.size() ; i++)
        {
            if(bills[i] == 10)
            {
                if(!fives)
                    return false;
                fives--;
                tens++;
            }
            else if (bills[i] == 20)
            {
                if(tens && fives)
                    tens--, fives--;
                else if(fives >= 3)
                    fives -=3;
                else
                    return false;
            }
            else
                fives++;  
        }
        return true;
    }
};