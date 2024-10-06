class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> w1,w2;
        function<vector<string>(string&)> split=[](string& sentence)->vector<string> {
            stringstream ss(sentence);
            string word;
            vector<string> words;
            while(ss>>word) words.push_back(word);
            return words;
        };
        w1=split(sentence1),w2=split(sentence2);
        if(w1.size()<w2.size()) swap(w1,w2);
        int m=w1.size(),n=w2.size(),left=0,right=0;
        while(left<n && w1[left]==w2[left]) left++;
        while(right<n && w1[m-right-1]==w2[n-right-1]) right++;
        return left+right>=n;
    }
};