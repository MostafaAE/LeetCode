class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int count{}, start{}, end{}, n = arr.size();
        
        while(end < n)
        {
            unordered_set<int> hashSet;
            for(int i = start ; i <= end ; ++i)
                hashSet.insert(arr[i]);
            
            bool validChunck{true};
            for(int i = start ; i <= end ; ++i)
            {
                if(!hashSet.count(i))
                {
                    validChunck = false;
                    break;
                }
            }
            
            ++end;
            
            if(validChunck)
                ++count, start = end;
        }
        
        return count;
    }
};