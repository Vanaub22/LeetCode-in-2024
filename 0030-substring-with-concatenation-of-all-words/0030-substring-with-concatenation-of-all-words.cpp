// Sliding Window Approach
class Solution {
private:
    bool checkSub(unordered_map<string,int> wordFreq, string s, int m, int n) {
        string word="";
        for(int i=0;i<n;i+=m) {
            string w=s.substr(i,m);
            if(wordFreq.find(w)!=wordFreq.end()) {
                if(wordFreq[w]<=0) return false;
                else wordFreq[w]--;
            }
            else return false;
        }
        return true;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int i=0,n=s.size(),m=words[0].size(),window_len=m*words.size();
        unordered_map<string,int> wordFreq;
        for(auto& word:words) wordFreq[word]++;
        while(i+window_len<=n) {
            if(checkSub(wordFreq,s.substr(i,window_len),m,window_len)) ans.emplace_back(i);
            i++;
        }
        return ans;
    }
};