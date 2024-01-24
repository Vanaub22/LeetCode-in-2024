class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.size();
        vector<int> occurrences;
        for(int i=0;i<n;i++) if(s[i]==c) occurrences.push_back(i);
        vector<int> answer(n);
        for(int i=0;i<n;i++) {
            int d=n,idx=0;
            for(int occurrence:occurrences) if(abs(occurrence-i)<=d) {
                d=abs(occurrence-i);
                idx=occurrence;
            }
            answer[i]=d;
        }
        return answer;
    }
};