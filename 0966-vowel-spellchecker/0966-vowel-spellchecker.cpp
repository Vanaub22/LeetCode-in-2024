class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        set<string> words;
        unordered_map<string,string> originalCase,vowelSubs;
        vector<string> answer;
        for(auto word:wordlist) {
            // No duplicate entries will be allowed to ensure that the match is always the first match
            words.insert(word);
            string lword=toLower(word),vsub=toLower(maskVowels(word));
            if(originalCase.find(lword)==originalCase.end()) originalCase[lword]=word;
            if(vowelSubs.find(vsub)==vowelSubs.end()) vowelSubs[vsub]=word;
        }
        for(string query:queries) {
            string lquery=toLower(query),vsub=toLower(maskVowels(query));
            if(words.find(query)!=words.end()) answer.push_back(query);
            else if(originalCase.find(lquery)!=originalCase.end()) answer.push_back(originalCase[lquery]);
            else if(vowelSubs.find(vsub)!=vowelSubs.end()) answer.push_back(vowelSubs[vsub]);
            else answer.push_back("");
        }
        return answer;
    }
    string toLower(string w) {
        for(char& c:w) c=tolower(c);
        return w; 
    }
    string maskVowels(string w) {
        for(char& c:w) if(isVowel(tolower(c))) c='*';
        return w;
    }
    bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
};