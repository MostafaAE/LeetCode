class AuthenticationManager {
private:
    // hash map to store each token and its expiry time
    unordered_map<string, int> tokens;
    int timeToLive;
public:
    AuthenticationManager(int timeToLive) : timeToLive(timeToLive) {}
    
    void generate(string tokenId, int currentTime) 
    {
        tokens.insert({tokenId, currentTime + timeToLive});
    }
    
    void renew(string tokenId, int currentTime) 
    {
        if(!tokens.count(tokenId) || tokens[tokenId] <= currentTime)
            return;
        tokens[tokenId] = currentTime + timeToLive;
    }
    
    int countUnexpiredTokens(int currentTime) 
    {
        int count{};
        for(auto &[token, expiryTime] : tokens)
            if(expiryTime > currentTime)
                count++;
        
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */