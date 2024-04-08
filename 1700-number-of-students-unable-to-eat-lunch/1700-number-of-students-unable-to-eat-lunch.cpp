class Solution {
public:
    /*
     * Approach:
     * Count the number of circular and square students, then keep feeding them until we can't, return the number of remaining students.
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(1)
     */
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        int circularStu{}, squareStu{};
        
        for(int stu : students)
            circularStu += stu == 0, squareStu += stu == 1;
        
        for(int sandwich : sandwiches)
        {
            if(sandwich == 1 && squareStu > 0)
                --squareStu;
            else if(sandwich == 0 && circularStu > 0)
                --circularStu;
            else
                break;
        }
        
        return circularStu + squareStu;
    }
};