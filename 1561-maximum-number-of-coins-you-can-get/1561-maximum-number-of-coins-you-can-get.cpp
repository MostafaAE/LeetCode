class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        int result{}, n = piles.size();

        sort(piles.begin(), piles.end(), greater<>());

        for(int i = 1 ; i < n/3*2 ; i += 2)
            result += piles[i];
        
        return result;
    }
};