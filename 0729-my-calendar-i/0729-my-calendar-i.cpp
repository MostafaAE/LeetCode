class MyCalendar {
private:
    set<pair<int, int>> calender;
public:
    MyCalendar() {
        
    }
    
    // O(logn)
    bool book(int start, int end) 
    {        
        auto nextInt = calender.lower_bound({start, end});
        if(nextInt != calender.end() && nextInt->first < end)
            return false;
        
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