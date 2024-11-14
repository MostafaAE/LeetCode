class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) 
    {
        int start{1}, end = 1e5 + 1, result{};
        
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            
            if(canDistribute(quantities, n, mid))
            {
                result = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        
        return result;
    }
    
    bool canDistribute(vector<int>& quantities, int n, double target)
    {
        int count{};
        for(int i = 0 ; i < quantities.size() ; ++i)
        {
            count += ceil(quantities[i] / target);
            if(count > n)
                return false;
        }
        return true;
    }
};