class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        for(int i=0;i<n;i++) {
            s=s.back()+s;
            s.pop_back();
            if(s==goal) return true;
        }
        return false;
    }
};