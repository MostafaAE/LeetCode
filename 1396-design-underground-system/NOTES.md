### Approach:
- Utilize two unordered_maps:
- checkInDetails: to store the check-in details of each customer by their ID.
- startToEnd: to store the count of customers and the total time spent by them between each pair of stations.
- For each check-in, record the station and time. For each check-out, calculate the time spent and update the startToEnd map accordingly.
- To get the average time between two stations, retrieve the count and total time from the startToEnd map and return the average.
​
### Complexity:
- **checkIn: `O(1)`**
- **checkOut: `O(1)`**
- **getAverageTime: `O(1)`**