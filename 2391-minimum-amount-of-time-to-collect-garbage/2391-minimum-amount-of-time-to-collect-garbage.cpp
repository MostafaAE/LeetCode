class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        int M = 0, P = 0, G = 0, result = garbage[0].size();

        for (int i = garbage.size() - 1; i > 0; i--) 
        {
            for (char ch : garbage[i]) 
            {
                if (ch == 'M') 
                    M = 1;
                else if (ch == 'P')
                    P = 1;
                else
                    G = 1;
            }

            result += travel[i - 1] * (M + P + G) + garbage[i].size();
        }

        return result;
    }
};