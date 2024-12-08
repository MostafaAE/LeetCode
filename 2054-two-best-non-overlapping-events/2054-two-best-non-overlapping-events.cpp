class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) 
    {
        int n = events.size(), result{};
        sort(events.begin(), events.end());
        vector<int> suffixMax(n+1, 0);
        
        for(int i = n-1 ; i >= 0 ; --i)
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
            
        for(int i = 0 ; i < n ; ++i)
        {
            int nextNonOverlappingIdx = binarySearch(events, i);
            
            result = max(result, events[i][2] + suffixMax[nextNonOverlappingIdx]);
        }
        
        return result;
    }
    
    int binarySearch(vector<vector<int>>& events, int idx)
    {
        int target = events[idx][1];
        
        int start = idx + 1, end = events.size() - 1;
        
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            
            if(events[mid][0] <= target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        
        return start;
    }
};