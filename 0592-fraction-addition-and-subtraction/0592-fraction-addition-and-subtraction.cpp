class Solution {
public:
    // Basic simulation using several conditonals and flags
    string fractionAddition(string exp) {
        if(exp[0]!='-') exp="+"+exp; // Adding '+' at the beginning to maintain format
        exp+='+'; // Adding a sign at the end to perform the last operation
        string numerator="",denominator="";
        char op; // Flag to indicate which operation to perform (addition / subtraction)
        bool num_flg=true; // Flag to indicate if we are collecting numerator or denominator
        int n=exp.length(),r_num=0,r_denom=1; // Storing initial result = 0 / 1
        for(int i=0;i<n;i++) {
            if(exp[i]=='+' || exp[i]=='-') {
                if(i==0) { 
                    op=exp[i]; // Storing the sign for the first operation
                    continue;
                }
                num_flg=true;
                int num=stoi(numerator),denom=stoi(denominator);
                // Performing the operation
                r_num=op=='+'?r_num*denom+num*r_denom:r_num*denom-num*r_denom;
                r_denom*=denom;
                numerator="",denominator=""; // Cleared
                op=exp[i]; // Storing the sign for the subsequent operation
            }
            else if(exp[i]=='/') num_flg=false; // Will collect denominator here onwards
            else {
                if(num_flg) numerator+=exp[i];
                else denominator+=exp[i];
            }
        }
        // Reducing the obtained fraction
        return to_string(r_num/abs(gcd(r_num,r_denom)))+"/"+to_string(r_denom/abs(gcd(r_num,r_denom)));
    }
};