/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/


class Solution {
private:
    unordered_map<int, Employee*> idToEmp;
    
public:
    /* 
    * Approach:
    * Depth-first search
    * 
    * Complexity:
    * Time Complexity : O(N)
    * Space Complexity : O(N)
    */
    int getImportance(vector<Employee*> employees, int id) 
    {
        for(Employee* e : employees)
            idToEmp[e->id] = e;
        
        return getTotalImportance(id);
    }
    
    int getTotalImportance(int id)
    {
        Employee* emp = idToEmp[id];
        
        int importance = emp->importance;
        
        for(int sub : emp->subordinates)
            importance += getTotalImportance(sub);
        
        return importance;
    }
};