class Solution {
public:
    string replaceWords(vector<string>& dict, string s) {
        string word,ans="",root;
        stringstream ss(s);
        while(ss>>word) {
            root=word;
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