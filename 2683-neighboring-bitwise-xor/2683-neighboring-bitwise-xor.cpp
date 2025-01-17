class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) 
    {
        int XOR{};

        for(int val : derived)
            XOR ^= val;
        
        return XOR == 0;
    }
};