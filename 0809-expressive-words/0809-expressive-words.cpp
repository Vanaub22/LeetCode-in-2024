class Solution {
private:
    void quantify(string s, auto& x, auto& y) {
        x.clear(),y.clear();
        char f=s[0];
        x[f]++;
        for(char c:s) {
            if(c!=f) {
                x[c]++;
                f=c;
            }
            y[c+to_string(x[c])]++;
        }
    }
    bool check(auto& x, auto& y, auto& a, auto& b) {
        if(x.size()!=a.size() || y.size()!=b.size()) return false;
        for(auto it:y) {
            string wg=it.first;
            int gsize=it.second;
            if(b[wg]<gsize || (b[wg]>gsize && b[wg]<3)) return false;
        }
        return true;
    }
public:
    int expressiveWords(string s, auto& words) {
        int res=0;
        unordered_map<char,int> groups,w_groups;
        unordered_map<string,int> group_size,w_group_size;
        quantify(s,groups,group_size);
        for(auto& word:words) {
            quantify(word,w_groups,w_group_size);
            if(check(w_groups,w_group_size,groups,group_size)) res++;
        }
        return res;
    }
};