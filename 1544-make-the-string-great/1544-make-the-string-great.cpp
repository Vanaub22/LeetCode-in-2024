class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(char c:s) {
            if(st.empty()) st.push(c);
            else if(isupper(c)) {
                if(st.top()==tolower(c)) st.pop();
                else st.push(c);
            }
            else {
                if(st.top()==toupper(c)) st.pop();
                else st.push(c);
            }
        }
        string good="";
        while(!st.empty()) {
            good+=st.top();
            st.pop();
        }
        reverse(good.begin(),good.end());
        return good;
    }
};