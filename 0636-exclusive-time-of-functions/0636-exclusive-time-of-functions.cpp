class Solution {
public:
    /* 
    * Approach:
    * Call Stack Simulation
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    vector<int> exclusiveTime(int n, vector<string>& logs) 
    {
        stack<vector<int>> st;
        vector<int> res(n, 0);
        
        for(string log : logs)
        {
            vector<int> parsedLog = parseLog(log);
            
            if(!st.empty())
                res[st.top()[0]] += parsedLog[2] - st.top()[2] + (parsedLog[1] == 1);
            
            // start of a function
            if(parsedLog[1] == 0)
                st.push(parsedLog);
            
            // end of a function
            if(parsedLog[1] == 1)
            {
                st.pop();
                if(!st.empty())
                    st.top()[2] = parsedLog[2] + 1;
            }
        }
        
        return res;
    }
    
    vector<int> parseLog(string log)
    {
        vector<int> res;
        stringstream ss(log);
        string s;
        
        while(getline(ss, s, ':'))
        {
            if(s == "start")
                res.push_back(0);
            else if(s == "end")
                res.push_back(1);
            else
                res.push_back(stoi(s));
        }
        
        return res;
    }
};