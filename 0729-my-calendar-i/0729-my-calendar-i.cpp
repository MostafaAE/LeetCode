class MyCalendar {
private:
    // set to store the intervals
    set<pair<int, int>> calender;
public:
    MyCalendar() {
        
    }
    
    // O(logn)
    bool book(int start, int end) 
    {
        // check if the end conflict with the next interval
        auto nextInt = calender.lower_bound({start, end});
        if(nextInt != calender.end() && nextInt->first < end)
            return false;
        
        // check if the start conflict with the previous interval
        if(nextInt != calender.begin())
        {
            auto prevInt = prev(nextInt);
            if(start < prevInt->second)
                return false;
        }
        
        calender.insert({start, end});
        return true;     
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */