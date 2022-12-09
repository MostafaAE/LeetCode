class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> seats;
public:
    // O(nlogn)
    SeatManager(int n) 
    {
        for(int i = 1 ; i <= n ; i++)
            seats.push(i);
    }
    
    // O(logn)
    int reserve() 
    {
        int ret = seats.top();
        seats.pop();
        return ret;
    }
    
    // O(logn)
    void unreserve(int seatNumber) 
    {
        seats.push(seatNumber);   
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */