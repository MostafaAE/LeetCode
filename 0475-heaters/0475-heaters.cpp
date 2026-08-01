class Solution {
public:
    /* 
    * Approach:
    * binary search the minimum radius
    * 
    * Complexity:
    * Time Complexity : O(nlogn + nlogm) where m is the maximum element in the houses and heaters
    * Space Complexity : O(1)
    */
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());
        
        int maxHouse = houses[(int)houses.size()-1];
        int maxHeater = heaters[(int)heaters.size()-1];
        
        int start = 0, end = max(maxHouse, maxHeater), answer{end};
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            
            if(possibleRadius(houses, heaters, mid))
                end = mid - 1 , answer = mid;
            else
                start = mid + 1;
        }
        
        return answer;
    }
    
    bool possibleRadius(vector<int>& houses, vector<int>& heaters, int radius)
    {
        int houseIdx = 0, housesCount = houses.size();
        for(int i = 0 ; i < (int)heaters.size() ; i++)
        {
            // Covered range [left, right] by the ith heater
            int heaterStart = heaters[i] - radius;
            int heaterEnd = heaters[i] + radius;
            
            while(houseIdx < (int)houses.size() && heaterStart <= houses[houseIdx] && houses[houseIdx] <= heaterEnd)
                houseIdx++; // cover more houses with ith heater

            if(houseIdx >= housesCount)
                return true;
        }

        return false;
    }
};