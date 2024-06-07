class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string word,ans="";
        stringstream ss(sentence);
        while(ss>>word) {
            string root=word;
            for(int i=0;i<word.size();i++) {
                vector<string>::iterator it=find(dict.begin(),dict.end(),word.substr(0,i));
                if(it!=dict.end() && (*it).length()<root.length()) root=*it;
            }
            ans+=root+" ";
        }
        ans.pop_back();
        return ans;
    }
};