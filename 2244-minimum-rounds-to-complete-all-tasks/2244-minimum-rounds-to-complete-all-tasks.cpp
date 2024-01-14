class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> freq;
        for(int task:tasks) freq[task]++;
        int rounds=0;
        for(auto it:freq) {
            int r=countRounds(it.second);
            if(r>=0) rounds+=r;
            else return r;
        }
        return rounds;
    }
    // Helper func. to greedily conduct the rounds
    int countRounds(int x) {
        int r=0;
        while(x>0) {
            if(x==1) return -1; // Task cannot be completed
            if(x!=4) x-=3;
            else x-=2;
            r++;
        }
        return r;
    }
};