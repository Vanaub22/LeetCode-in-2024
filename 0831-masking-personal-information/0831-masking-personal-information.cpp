class Solution {
public:
    string maskPII(string s) {
        int n=s.length();
        string masked="";
        if(isalpha(s.back())) {
            // E-mail address
            bool domain=false;
            for(int i=0;i<n;i++) {
                s[i]=tolower(s[i]);
                if(s[i]=='@') {
                    domain=true;
                    masked=string(1,s[0])+"*****"+s[i-1]+"@";
                }
                else if(domain) masked+=s[i];
            }
        }
        else {
            // Phone Number
            string cleaned;
            for(char c:s) if(isdigit(c)) cleaned+=c;
            s=cleaned;
            n=s.length();
            masked="***-***-"+s.substr(n-4,4);
            masked=n==10?masked:"+"+string(n-10,'*')+"-"+masked;
        }
        return masked;
    }
};