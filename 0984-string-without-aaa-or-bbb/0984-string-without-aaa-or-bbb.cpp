class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res="";
        char turn=a>b?'a':'b';
        int n=a+b;
        do {
            if(turn=='a') {
                if(a>=2 && a>b) {
                    res+="aa";
                    a-=2;
                }
                else if(a>0) {
                    res+="a";
                    a--;
                }
                turn='b';
            }
            else {
                if(b>=2 && b>a) {
                    res+="bb";
                    b-=2;
                }
                else if(b>0) {
                    res+="b";
                    b--;
                }
                turn='a';
            }
        } while(res.length()!=n); 
        return res;
    }
};