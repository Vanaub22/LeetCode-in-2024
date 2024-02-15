class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),[&](string& w1, string& w2) {
            return w1.size()>w2.size();
        });
        string ref="";
        vector<string> encoding;
        for(auto& word:words) {
            bool included=false;
            for(string& w:encoding) {
                if(w.substr(w.length()-word.length())==word) {
                    included=true;
                    break;
                }
            }
            if(!included) {
                ref+=word+"#";
                encoding.push_back(word);
            }
        }
        return ref.size();
    }
};