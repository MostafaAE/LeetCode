class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) 
    {
        map<int, unordered_set<int>> minValToIndecies;
        map<int, unordered_set<int>> maxValToIndecies;
        
        for(int i = 0 ; i < arrays.size() ; ++i)
        {
            minValToIndecies[arrays[i].front()].insert(i);
            maxValToIndecies[arrays[i].back()].insert(i);
        }
        
        auto minItr = minValToIndecies.begin();
        auto maxItr = maxValToIndecies.rbegin();
        int result{INT_MIN};
        for(int i = 0 ; i < 3 && minItr != minValToIndecies.end() && maxItr != maxValToIndecies.rend() ; ++i)
        {
            int minVal = minItr->first;
            unordered_set<int> minIndecies = minItr->second;
            
            int maxVal = maxItr->first;
            unordered_set<int> maxIndecies = maxItr->second;
            
            for(auto idx : minIndecies)
                if(maxIndecies.size() > 1 || !maxIndecies.count(idx))
                    result = max(result, abs(maxVal - minVal));
            
            if(i == 0)
                maxItr++;
            
            if(i == 1)
                minItr++, maxItr--;
        }
        
        return result;
    }
};