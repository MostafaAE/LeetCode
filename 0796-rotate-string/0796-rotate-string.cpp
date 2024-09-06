class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        if(s.size() != goal.size())
            return false;
        
        vector<int> indecies;
        
        for(int i = 0 ; i < goal.size() ; ++i)
            if(goal[i] == s[0])
                indecies.push_back(i);
        
        for(int i = 0 ; i < indecies.size() ; ++i)
        {
            string half1 = goal.substr(indecies[i]);
            string half2 = goal.substr(0, indecies[i]);
            if(s == half1 + half2)
                return true;
        }
        
        return false;
    }
};