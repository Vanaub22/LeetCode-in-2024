class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth=0;
        for(string& log:logs) if(log=="../") depth=depth?depth-1:depth;
        else if(log!="./") depth++;
        return depth;
    }
};