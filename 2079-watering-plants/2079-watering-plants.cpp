class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) 
    {
        int n = plants.size(), remainingCapacity = capacity, result{};

        for(int i = 0 ; i < n ; ++i)
        {
            ++result;
            if(remainingCapacity < plants[i])
            {
                remainingCapacity = capacity;
                result += 2 * i;
            }

            remainingCapacity -= plants[i];
        }
        
        return result;
    }
};