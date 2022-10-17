class Solution {
public:

    string defangIPaddr(string address) 
    {
        string result{};
        
        for(int i = 0 ; i < (int)address.size() ; i++)
        {
            if(address[i] == '.')
                result += "[.]";
            else
                result += address[i]; 
        }
        
        return result;
        
    }
};