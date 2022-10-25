class Solution {
public:
    int climbStairs(int n) 
    {
        if(n <= 2)
            return n;
        
        int prev = 1, cur = 2;
        for(int i = 3 ; i <= n ; i++)
            swap(prev,cur), cur+=prev;
        
        return cur;
    }
};