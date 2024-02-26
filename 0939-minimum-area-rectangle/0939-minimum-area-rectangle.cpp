class Solution {
public:
    /* 
    * Approach:
    * Keep Y values in a vector, Keep a hashmap that map each Y value to a set of different X values (sorted), Iterate using two loops keeping track of the minimum area.
    * 
    * Complexity:
    * Time Complexity : O(n^3)
    * Space Complexity : O(n)
    */
    int minAreaRect(vector<vector<int>>& points) 
    {        
        vector<int> yValues;
        unordered_map<int, set<int>> yToX;
        int minArea{INT_MAX};
        bool foundArea{};
        
        for(auto &p : points)
        {
            int x = p[0], y = p[1];
            if(yToX.count(y))
                yToX[y].insert(x);
            else
            {
                set<int> xValues;
                xValues.insert(x);
                yToX.insert({y, xValues});
                yValues.push_back(y);
            }
        }
        
        for(int i = 0 ; i < (int)yValues.size() ; i++)
        {
            for(int j = i + 1 ; j < (int)yValues.size() ; j++)
            {
                int y1 = yValues[i], y2 = yValues[j], prev = -1;
            
                auto itr1 = yToX[y1].begin();
                auto itr2 = yToX[y2].begin();

                while(itr1 != yToX[y1].end() && itr2 != yToX[y2].end())
                {
                    if(*itr1 == *itr2)
                    {
                        if(prev != -1)
                        {
                            minArea = min(minArea, abs(y1 - y2) * abs(*itr1 - prev));
                            foundArea = true;
                        }
                        prev = *itr1;
                        itr1++;
                        itr2++;
                    }
                    else if (*itr1 < *itr2)
                        itr1++;
                    else
                        itr2++;
                }
            }
        }
        
        if(!foundArea)
            return 0;
        
        return minArea;
    }
};