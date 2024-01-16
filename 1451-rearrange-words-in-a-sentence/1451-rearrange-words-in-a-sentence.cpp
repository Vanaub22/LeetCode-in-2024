class Solution {
private:
    struct ordered_word {
        string word;
        int sz,order;
    };
public:
    static bool comp(ordered_word& a, ordered_word& b) {
        return a.sz==b.sz?a.order<b.order:a.sz<b.sz;
    }
    string arrangeWords(string text) {
        stringstream ss(text);
        string word,res="";
        vector<ordered_word> c; 
        int i=0;
        while(ss>>word) {
            ordered_word o_word;
            word[0]=isupper(word[0])?tolower(word[0]):word[0];
            o_word.word=word,o_word.order=i,o_word.sz=word.length();
            c.push_back(o_word);
            i++;
        }
        sort(c.begin(),c.end(),comp);
        for(auto& w:c) res+=w.word+" ";
        res.pop_back();
        res[0]=islower(res[0])?toupper(res[0]):res[0];
        return res;
    }
};