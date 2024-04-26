class Solution {
public:
    /*
     * Approach:
     * Parse each email to remove any characters after '+' and remove '.' characters from the local name.
     * Add the parsed email to a hashset to keep track of unique emails.
     * Finally, return the size of the hashset, which represents the number of unique emails.
     *
     * Complexity:
     * - Time Complexity: O(N*L) where N is the number of emails and L is the length of each email.
     * - Space Complexity: O(N)
     */
    int numUniqueEmails(vector<string>& emails) 
    {
        unordered_set<string> uniqueEmails;
        
        for(string email : emails)
            uniqueEmails.insert(parseEmail(email));

        return uniqueEmails.size();
    }
    
    string parseEmail(string email)
    {
        stringstream ss(email);
        
        string localName, domainName, parsedLocalName{};
        getline(ss, localName, '@');
        getline(ss, domainName);

        for(char c : localName)
        {
            if(c == '+')
                break;
            if(c != '.')
                parsedLocalName += c;
        }
        return parsedLocalName + "@" + domainName;
    }
};
