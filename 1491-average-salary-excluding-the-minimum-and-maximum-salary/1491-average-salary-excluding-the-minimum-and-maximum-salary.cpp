class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    double average(vector<int>& salary) 
    {
        int minSalary{INT_MAX}, maxSalary{INT_MIN}, size = (int)salary.size();
        double sum{};
        for(int i = 0 ; i < size ; i++)
        {
            if(salary[i] < minSalary)
                minSalary = salary[i];
            if(salary[i] > maxSalary)
                maxSalary = salary[i];
            sum += salary[i];
        }
        
        sum = sum - minSalary - maxSalary;
        
        return sum / (size-2);
        
    }
};