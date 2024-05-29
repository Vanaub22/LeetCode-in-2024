class Solution {
public:
    int numSteps(string s) {
        int n=s.size(),steps=0;
        while(n!=1) {
            if(s[n-1]=='1') {
                bool added=false;
                for(int i=n-1;i>=0;i--) {
                    if(s[i]=='1') s[i]='0';
                    else {
                        s[i]='1';
                        added=true;
                        break;
                    }
                }
                if(!added) s='1'+s;
            }
            else s.pop_back();
            n=s.size();
            steps++;
        }
        return steps;
    }
};