class Solution {
public:
    /**
     * Approach:
     * - Sort the folder paths lexicographically.
     * - Initialize a vector to store the result with the first folder, as it's the smallest lexicographically.
     * - For each subsequent folder, check if it is a subfolder of the current root folder by searching for its path as a prefix.
     * - If it's not a subfolder, add it to the result and update the current root folder.
     * 
     * Complexity:
     * - Time Complexity: O(N * L * logN), where `N` is the number of folders and `L` is the maximum length of a folder.
     * - Space Complexity: O(N * L), for storing the sorted folders and the result.
     */

    vector<string> removeSubfolders(vector<string>& folder) 
    {
        // Step 1: Sort the folders lexicographically
        sort(folder.begin(), folder.end());
        
        vector<string> result;
        
        result.push_back(folder[0]);
        string curFolder = folder[0] + "/";
        
        // Step 2: Check each folder to see if it's a subfolder
        for(int i = 1 ; i < folder.size() ; ++i)
        {
            int pos = folder[i].find(curFolder);
            
            // If folder[i] is not a subfolder of curFolder, add it to result
            if(pos != 0)  // Means curFolder is not a prefix of folder[i]
            {
                result.push_back(folder[i]);
                curFolder = folder[i] + "/"; 
            }
        }
        
        return result;
    }
};
