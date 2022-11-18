class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1) >> neglecting the output space
    */
    string interpret(string command) 
    {
        string result{};
        
        for(int i = 0 ; i <(int)command.size() ; i++)
        {
            if(command[i] == 'G' || command[i] == 'a' || command[i] == 'l')
                result += command[i];
            
            else if(command[i] == ')' && command[i-1] == '(')
                result += 'o';
        }
        
        return result;
    }
};