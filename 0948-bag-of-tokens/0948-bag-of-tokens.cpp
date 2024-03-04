class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int low=0,high=tokens.size()-1,score=0,highestScore=0;
        while(low<=high && (power>=tokens[low] || score>0)){
            while(low<=high && power>=tokens[low]) {
                power-=tokens[low];
                low++;
                score++;
            }
            highestScore=max(highestScore,score);
            if(low<=high && score>0) {
                power+=tokens[high];
                score--;
                high--;
            }
        }
        return highestScore;
    }
};