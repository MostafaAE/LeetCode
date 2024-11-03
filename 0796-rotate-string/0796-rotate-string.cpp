class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        if(s.size() != goal.size())
            return false;
        
        string doubleStr = goal + goal;
        
        return doubleStr.find(s) != string::npos;
    }
};