class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkInDetails;
    unordered_map<string, unordered_map<string, pair<int, int>>> startToEnd;
public:
    /*
     * Approach:
     * Utilize two unordered_maps:
     * - checkInDetails: to store the check-in details of each customer by their ID.
     * - startToEnd: to store the count of customers and the total time spent by them between each pair of stations.
     * For each check-in, record the station and time. For each check-out, calculate the time spent and update the startToEnd map accordingly.
     * To get the average time between two stations, retrieve the count and total time from the startToEnd map and return the average.
     *
     * Complexity:
     * - checkIn: O(1)
     * - checkOut: O(1)
     * - getAverageTime: O(1)
     */
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkInDetails[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [startStation, time] = checkInDetails[id];
        
        if(!startToEnd[startStation].count(stationName))
            startToEnd[startStation][stationName] = {0, 0};
        
        startToEnd[startStation][stationName].first++;
        startToEnd[startStation][stationName].second += t - time;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto [customersCount, totalTime] = startToEnd[startStation][endStation];
        return (double)totalTime / customersCount;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */