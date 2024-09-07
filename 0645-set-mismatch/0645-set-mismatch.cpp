class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int n = nums.size(), dup;

        vector<bool> visited(n);

        for(int i = 0 ; i < n ; ++i)
        {
            if(visited[nums[i]])
                dup = nums[i];

            visited[nums[i]] = 1;
        }
        
        for(int i = 1 ; i <= n ; ++i)
            if(!visited[i])
                return {dup, i};

        return {};
    }
};