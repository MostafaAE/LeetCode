class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) 
    {
        int result{};
        for(auto op : operations)
            result += getOperationValue(op);
            
        return result;
    }

    int getOperationValue(string op)
    {
        return op[0] == '-' || op[2] == '-' ? -1 : 1;
    }
};