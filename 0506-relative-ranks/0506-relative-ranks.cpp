class Solution {
public:
    /*
    * Approach:
    * - Use a priority queue (max heap) to store {score, index} pairs.
    * - Pop elements from the max heap one by one, assign ranks to the corresponding indices in the result vector.
    *
    * Complexity:
    * - Time Complexity: O(n logn), where n is the number of scores.
    * - Space Complexity: O(n).
    */
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        vector<string> result(score.size());
        priority_queue<pair<int, int>> maxHeap;
        
        //O(n logn)
        for(int i = 0 ; i < score.size() ; ++i)
            maxHeap.push({score[i], i});
        
        //O(n logn)
        int place = 1;
        while(!maxHeap.empty())
        {
            int idx = maxHeap.top().second;
            result[idx] = getRank(place);
            ++place;
            maxHeap.pop();
        }
        
        return result;
    }
    
    string getRank(int place)
    {
        vector<string> medals{"Gold Medal", "Silver Medal", "Bronze Medal"};
        if(place <= medals.size())
            return medals[place - 1];
        else
            return to_string(place);
    }
};