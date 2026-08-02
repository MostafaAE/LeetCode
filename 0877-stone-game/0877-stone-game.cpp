class Solution {
public:
    bool stoneGame(vector<int>& piles) 
    {
        int left{}, right = (int)piles.size() - 1, turn{};
        vector<int> players(2, 0);

        while(left <= right)
        {
            if(piles[left] >= piles[right])
            {
                players[turn] += piles[left++];
            }
            else
            {
                players[turn] += piles[right--];
            }

            turn != turn;
        }

        return players[0] > players[1];
    }
};