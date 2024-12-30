class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        int kidsCount = candies.size();
        vector<bool> result(kidsCount, true);
        int maxCandies = *max_element(candies.begin(), candies.end());

        for(int i = 0 ; i < kidsCount ; ++i)
            result[i] = candies[i]+extraCandies >= maxCandies;
        
        return result;
    }
};