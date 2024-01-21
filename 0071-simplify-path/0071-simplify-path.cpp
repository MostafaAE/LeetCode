class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dirs;
        string result = "", curDir = "";
        path += "/";
        
        for(int i = 1 ; i < (int)path.size() ; i++)
        {
            if(path[i] == '/')
            {
                if(curDir == "")
                    continue;
                
                if(curDir == "..")
                {
                    if(!dirs.empty())
                        dirs.pop();
                }
                else if (curDir != ".")
                    dirs.push(curDir);
                
                curDir = "";
            }
            else
                curDir += path[i];
        }
        
        while(!dirs.empty())
        {
            result = "/" + dirs.top() + result;
            dirs.pop();
        }
        
        if(result.empty())
            result += "/";
        
        return result;
    }
};