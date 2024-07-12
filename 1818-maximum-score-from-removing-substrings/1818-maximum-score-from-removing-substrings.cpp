// Greedy Approach (2-pass): Remove the more profitable combination first
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score=0;
        stack<char> stk;
        // Pass 1: Removing the combination that will yield more score
        for(char c:s) {
            if(stk.empty()) stk.push(c);
            else if(stk.top()=='a' && c=='b' && x>y) {
                score+=x;
                stk.pop();
            }
            else if(stk.top()=='b' && c=='a' && x<y) {
                score+=y;
                stk.pop();
            }
            else stk.push(c);
        }
        // Assigning the left-over characters to the string once again
        s.clear();
        while(!stk.empty()) {
            s+=stk.top();
            stk.pop();
        }
        reverse(s.begin(),s.end());
        // Pass 2: Removing the other combination
        for(char c:s) {
            if(stk.empty()) stk.push(c);
            else if(stk.top()=='a' && c=='b' && x<=y) {
                score+=x;
                stk.pop();
            }
            else if(stk.top()=='b' && c=='a' && x>=y) {
                score+=y;
                stk.pop();
            }
            else stk.push(c);
        }
        return score;
    }
};