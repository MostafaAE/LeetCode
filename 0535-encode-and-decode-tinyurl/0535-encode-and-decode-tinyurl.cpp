class Solution {
private:
    string baseUrl = "http://tinyurl.com/";
    int id{1};
    unordered_map<string, string> shortToLong;
    unordered_map<string, string> longToShort;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) 
    {
        if(longToShort.count(longUrl))
            return longToShort[longUrl];
        
        // generate a random id
        // in a real system we may generate a random id of 7 digits for example so we can serve 62^7 ~= 3500 billion URLs
        string shortUrl = baseUrl + to_string(id++);
        longToShort[longUrl] = shortUrl;
        shortToLong[shortUrl] = longUrl;
        
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) 
    {
        return shortToLong[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));