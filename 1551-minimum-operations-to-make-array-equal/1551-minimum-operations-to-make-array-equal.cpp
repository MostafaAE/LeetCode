class Solution {
public:
    int minOperations(int n) 
    {
        int result{}, operations = n - 1;
        while(operations > 0)
        {
            result += operations;
            operations -= 2;
        }
        
        return result;
    }
};