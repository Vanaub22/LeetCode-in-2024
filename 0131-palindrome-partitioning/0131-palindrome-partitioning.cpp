class Solution {
private:
    bool isPalindrome(auto& s, int i, int j) {
        while(i<j) if(s[i++]!=s[j--]) return false;
        return true;
    }
    void partitioning(int i, auto& partition, auto& partitions, auto& s) {
        if(i==s.size()) {
            partitions.push_back(partition);
            return;
        }
        for(int j=i;j<s.size();j++) {
            if(isPalindrome(s,i,j)) {
                partition.push_back(s.substr(i,j-i+1));
                partitioning(j+1,partition,partitions,s);
                partition.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        vector<vector<string>> partitions;
        partitioning(0,partition,partitions,s);
        return partitions;
    }
};