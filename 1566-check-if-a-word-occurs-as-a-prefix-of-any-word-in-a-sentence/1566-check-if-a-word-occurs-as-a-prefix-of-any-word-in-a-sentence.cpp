class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int n=searchWord.size(),i=0;
        while(ss>>word) {
            i++;
            if(word.substr(0,n)==searchWord) return i;
        }
        return -1;
    }
};