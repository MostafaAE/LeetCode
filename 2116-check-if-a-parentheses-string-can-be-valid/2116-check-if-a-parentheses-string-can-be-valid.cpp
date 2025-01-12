class Solution {
public:
    bool canBeValid(string s, string locked) 
    {
        int n = s.size(), openBrackets{}, unlockedCount{};

        if(n&1)
            return false;

        for(int i = 0 ; i < n ; ++i)
        {
            // If the parenthese is '(' or ')' but unlocked
            if(locked[i] == '0')
            {
                ++unlockedCount;
            }
            // If the parenthese is '(' and locked
            else if(s[i] == '(')
            {
                ++openBrackets;
            }
            // If the parenthese is ')' and locked
            // We have to find a match
            else if(s[i] == ')')
            {
                
                if(openBrackets > 0)            // Consume from locked
                    --openBrackets;
                else if(unlockedCount > 0)      // Consume from unlocked
                    --unlockedCount;
                else
                    return false;
            }
        }

        // Match remaining open brackets with unlocked characters.
        int balance = 0;
        for (int i = n - 1; i >= 0; --i) 
        {
            if (locked[i] == '0') 
            {
                balance--;
                unlockedCount--;
            } 
            else if (s[i] == '(') 
            {
                balance++;
                openBrackets--;
            } 
            else if (s[i] == ')') 
            {
                balance--;
            }
            if (balance > 0) 
            {
                return false;
            }
            if (unlockedCount == 0 and openBrackets == 0) 
            {
                break;
            }
        }

        if (openBrackets > 0) {
            return false;
        }

        return true;
    }
};