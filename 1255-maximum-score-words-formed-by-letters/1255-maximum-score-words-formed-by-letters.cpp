class Solution {
private:
    // Helper fn. to check if the word can be formed with remaining letters
    bool canBeFormed(auto& word, int freq[]) {
        int f[26]={0};
        for(char c:word) f[c-'a']++;
        for(int i=0;i<26;i++) if(f[i]>freq[i]) return false;
        return true;
    }
    // Helper fn. to calculate the score of the words
    int calcScore(auto& word, auto& score) {
        int ans=0;
        for(char c:word) ans+=score[c-'a'];
        return ans;
    }
    // Backtracking fn. to find the best valid selection of words to maximize score
    int solve(int i, auto& words, auto& freq, int wordScores[]) {
        if(i==words.size()) return 0;
        int res=solve(i+1,words,freq,wordScores);
        if(canBeFormed(words[i],freq)) {
            for(char c:words[i]) freq[c-'a']--;
            res=max(res,wordScores[i]+solve(i+1,words,freq,wordScores));
            for(char c:words[i]) freq[c-'a']++; // Backtracking
        }
        return res;
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int freq[26]={0},n=words.size(),wordScores[n];
        bzero(wordScores,sizeof(wordScores));
        // Precomputing the score for each word
        for(int i=0;i<n;i++) for(char c:words[i]) wordScores[i]+=score[c-'a'];
        for(char c:letters) freq[c-'a']++;
        return solve(0,words,freq,wordScores);
    }
};