class Solution {
public:
    // Monotonic Stack solution in O(N) T.C.
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> answer(n,0);
        stack<int> s;
        s.push(0);
        for(int i=1;i<n;i++) {
            while(!s.empty() && temperatures[s.top()]<temperatures[i]) {
                answer[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return answer;
    }
};