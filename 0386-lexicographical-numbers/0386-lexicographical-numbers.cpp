class Solution {
public:
    vector<int> lexicalOrder(int n) 
    {
        vector<int> result;
        
        for(int i = 1 ; i <= n && i <= 9 ; ++i)
        {
            result.push_back(i);
            generateNums(n, i*10, result);
        }
        
        return result;
    }
    
    void generateNums(int n, int num, vector<int>& result)
    {   
        if(num > n)
            return;
        
        int iterations = (num % 10 + 1) * 10;
        for(int i = 0 ; num + i <= n && i < iterations ; ++i)
        {
            int curNum = num + i;
            result.push_back(curNum);
            generateNums(n, curNum * 10, result);
        }
    }
};