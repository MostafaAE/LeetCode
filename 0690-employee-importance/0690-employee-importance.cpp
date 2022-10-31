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
    * depth first search
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    int getImportance(vector<Employee*> employees, int id) 
    {
        for(Employee *emp : employees)
            idToEmp[emp->id] = emp;
        
        return dfs(id);
    }
    
    int dfs(int id)
    {
        int result = idToEmp[id]->importance;
        
        for(int neighbourId : idToEmp[id]->subordinates)
            result += dfs(neighbourId);
        
        return result;
    }
};