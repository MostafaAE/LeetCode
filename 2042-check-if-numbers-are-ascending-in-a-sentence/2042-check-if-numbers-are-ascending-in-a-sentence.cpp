class Solution {
public:
    bool areNumbersAscending(string s) 
    {
        s += " ";

        int n = s.size(), prev = -1;
        
        string cur{};
        for(int i = 0 ; i < n ; ++i)
        {
            if(s[i] == ' ')
            {
                if('0' <= cur[0] && cur[0] <= '9')
                {
                    int val = stoi(cur);

                    if(val <= prev)
                        return false;
                    
                    prev = val;
                }
                cur = "";
            }
            else
            {
                cur += s[i];
            }
        }

        return true;
    }
};