class AuthenticationManager {
public:
    unordered_map<string,int> tokenExpiry; // To map tokens to their corresponding expiry times
    int timeToLive;
    AuthenticationManager(int timeToLive) {
        this->timeToLive=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokenExpiry[tokenId]=currentTime+this->timeToLive;
    }
    
    void renew(string tokenId, int currentTime) {
        if(tokenExpiry.find(tokenId)==tokenExpiry.end()) return;
        if(tokenExpiry[tokenId]<=currentTime) return;
        tokenExpiry[tokenId]=currentTime+this->timeToLive; // Renewal
    }
    
    int countUnexpiredTokens(int currentTime) {
        int unexpired=0;
        for(auto& rec:tokenExpiry) if(rec.second>currentTime) unexpired++;
        return unexpired;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */