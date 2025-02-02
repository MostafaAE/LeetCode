class Solution {
public:
    bool checkString(string s) 
    {
        bool isBSeen{};

        for(char c : s)
        {
            if(c == 'b')
                isBSeen = true;
            else if(isBSeen)
                return false;
        }

        return true;
    }
};