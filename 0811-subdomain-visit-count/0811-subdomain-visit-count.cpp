class Solution {
public:
    /*
    * Approach:
    * - Use an unordered map to store the count of each subdomain.
    * - Iterate through each count-domain pair, get the start index of each subdomain, and update the count for each subdomain.
    * - Finally, construct the result vector by combining the count and domain for each entry in the map.
    *
    * Complexity:
    * - Time Complexity: O(n * m), where n is the number of count-domain pairs and m is the average length of a domain.
    * - Space Complexity: O(n * m), for storing the count-domain pairs.
    */
    vector<string> subdomainVisits(vector<string>& cpdomains) 
    {
        vector<string> result;
        unordered_map<string, int> domainToCount;
        for(string cpdomain : cpdomains)
        {
            vector<int> subdomainStartIdx = getSubdomainStartIdx(cpdomain);
            int count = stoi(cpdomain.substr(0, subdomainStartIdx[0] -1));
            
            for(int i = 0 ; i < subdomainStartIdx.size() ; ++i)
                domainToCount[cpdomain.substr(subdomainStartIdx[i])] += count;
        }
        
        for(auto &[domain, count] : domainToCount)
            result.push_back(to_string(count) + " " + domain);
        
        return result;
    }
    
    // O(m)
    vector<int> getSubdomainStartIdx(string cpdomain)
    {
        vector<int> result;
        for(int i = 0 ; i < cpdomain.size() ; ++i)
            if(cpdomain[i] == ' ' || cpdomain[i] == '.')
                result.push_back(i + 1);
        
        return result;
    }
};