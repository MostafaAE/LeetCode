class Solution {
public:
    /**
     * Approach:
     * - First, create a list of arrival times associated with the original index of each friend.
     * - Sort the list by the arrival time to simulate each friend's arrival in chronological order.
     * - Use two min-heaps:
     *   - One to track available chairs in ascending order.
     *   - Another to track the chairs that will become available, based on the friends' leaving times.
     * - For each friend's arrival:
     *   - Remove any chairs from the "busy" heap if the leave time has passed, pushing them into the "available" heap.
     *   - Assign the friend the smallest available chair, or the next available chair if no chairs are free.
     *   - Track the target friend's chair and return it as soon as they arrive.
     * 
     * Complexity:
     * - Time Complexity: O(n log n), where `n` is the number of friends. Sorting the arrival list takes O(n log n), and each operation with the heaps is O(log n).
     * - Space Complexity: O(n), due to the heaps and the storage for arrival times.
     */
    int smallestChair(vector<vector<int>>& times, int targetFriend) 
    {
        int n = times.size();
        
        vector<pair<int, int>> arrivalToIndex;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> charAvailableTime;
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        int nextChair{};
        
        for(int i = 0 ; i < n ; ++i)
            arrivalToIndex.push_back({times[i][0], i});
        
        sort(arrivalToIndex.begin(), arrivalToIndex.end());
        
        for(int i = 0 ; i < n ; ++i)
        {
            int arrivalTime = arrivalToIndex[i].first;
            int index = arrivalToIndex[i].second;
            int pickedChair{};
            while(!charAvailableTime.empty() && arrivalTime >= charAvailableTime.top().first)
            {
                availableChairs.push(charAvailableTime.top().second);
                charAvailableTime.pop();
            }
            
            if(!availableChairs.empty())
            {
                pickedChair = availableChairs.top();
                availableChairs.pop();
                charAvailableTime.push({times[index][1], pickedChair});
            }
            else
            {
                pickedChair = nextChair++;
                charAvailableTime.push({times[index][1], pickedChair});
            }
            
            if(targetFriend == index)
                return pickedChair;
        }
        
        return 0;
    }
};