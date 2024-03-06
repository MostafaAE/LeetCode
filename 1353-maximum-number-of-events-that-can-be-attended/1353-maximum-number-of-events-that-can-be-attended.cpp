class Solution {
public:
    /*
     * Approach:
     * Line Sweep approach:
     * Sort events by start date, then end date, then brute force on days (sweep) as long as we have events or items in the heap.
     *
     * Complexity:
     * Time Complexity : O(nlogn)
     * Space Complexity : O(n)
     */
    int maxEvents(vector<vector<int>>& events) 
    {
        int event{}, sz{(int)events.size()}, numEvents{};
        priority_queue<int, vector<int>, greater<int>> mnHeap; // heap of end values
        
        // sort by start date, then end date
        sort(events.begin(), events.end());
        
        // brute force on days (sweep) as long as we have events or items in the heap
        for(int day = 1 ; event < sz || !mnHeap.empty(); day++)
        {
            // remove passed events
            while(!mnHeap.empty() && mnHeap.top() < day)
                mnHeap.pop();
            
            // jump to the next event
            if(event < sz && mnHeap.empty())
                day = max(day, events[event][0]);
            
            // add today events
            while(event < sz && events[event][0] == day)
                mnHeap.push(events[event++][1]);
            
            // take the event ending first
            if(!mnHeap.empty())
            {
                numEvents++;
                mnHeap.pop();
            }
        }
        
        return numEvents;
    }
};