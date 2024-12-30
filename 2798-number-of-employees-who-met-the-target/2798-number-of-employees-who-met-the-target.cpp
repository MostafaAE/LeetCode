class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) 
    {
        int numberOfEmployeesMetTarget{};

        for(int hoursWorked : hours)
            numberOfEmployeesMetTarget += (hoursWorked >= target);
        
        return numberOfEmployeesMetTarget;
    }
};