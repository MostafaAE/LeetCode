class MyCalendar {
private:
    // map to store the intervals
    map<int, int> calender;
public:
    MyCalendar() {
        
    }
    
    // O(logn)
    bool book(int start, int end) 
    {
        auto itr = calender.upper_bound(start);
        if(itr == calender.end() || end <= itr->second)
        {
            calender[end] = start;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */