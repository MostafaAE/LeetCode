class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        int n = boxes.size(), curState{};
        vector<int> prefix(n+1, 0), result(n, 0);

        prefix[0] = getBoxValue(boxes[0]);
        for(int i = 1 ; i < n ; ++i)
        {
            prefix[i] += prefix[i-1] + getBoxValue(boxes[i]);
            curState += i * getBoxValue(boxes[i]);
        }

        prefix[n] = prefix[n-1];
        result[0] = curState;
        for(int i = 1 ; i < n ; ++i)
        {
            int boxValue = getBoxValue(boxes[i]);
            int leftDiff = prefix[i] - boxValue; // Get all values to the left
            int rightDiff = prefix[n] - prefix[i]; // Get all values to the right

            // We got closer to the values to right, and got farther to the values to the left
            curState = curState - rightDiff + leftDiff - boxValue;
            result[i] = curState;
        }

        return result;
    }

    int getBoxValue(char c)
    {
        return c - '0';
    }
};