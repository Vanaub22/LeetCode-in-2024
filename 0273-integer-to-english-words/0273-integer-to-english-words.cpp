class Solution {
public:
    string numberToWords(int num) {
        if(num==0) return("Zero");
        string str_num=to_string(num),billions,millions,thousands,rest;
        int n=str_num.length();
        str_num=string(12-n,'0')+str_num;
        billions=convert999(str_num.substr(0,3));
        millions=convert999(str_num.substr(3,3));
        thousands=convert999(str_num.substr(6,3));
        rest=convert999(str_num.substr(9,3));
        str_num="";
        if(billions!="") str_num+=billions+" Billion";
        if(millions!="") str_num+=millions+" Million";
        if(thousands!="") str_num+=thousands+" Thousand";
        if(rest!="") str_num+=rest;
        return(str_num.substr(1,str_num.length()-1));     
    }
    string convert999(string num){
        if(num=="000") return "";
        string converted="";
        unordered_map<string,string> doubleDigit={{"9","Ninety"},{"8","Eighty"},{"7","Seventy"},{"6","Sixty"},{"5","Fifty"},{"4","Forty"},{"3","Thirty"},{"2","Twenty"},{"19","Nineteen"},{"18","Eighteen"},{"17","Seventeen"},{"16","Sixteen"},{"15","Fifteen"},{"14","Fourteen"},{"13","Thirteen"},{"12","Twelve"},{"11","Eleven"},{"10","Ten"}};
        unordered_map<char,string> singleDigit={{'9',"Nine"},{'8',"Eight"},{'7',"Seven"},{'6',"Six"},{'5',"Five"},{'4',"Four"},{'3',"Three"},{'2',"Two"},{'1',"One"},{'0',""}};
        string hundreds="",tens="",ones="",str_num="";
        if(num[0]>'0') hundreds=singleDigit[num[0]];
        if(num[1]>'1'){
            tens=doubleDigit[string(1,num[1])];
            ones=singleDigit[num[2]];
        }
        else if(num[1]=='1') tens=doubleDigit[num.substr(1,2)];
        else ones=singleDigit[num[2]];
        if(hundreds!="") converted+=" "+hundreds+" Hundred";
        if(tens!="") converted+=" "+tens;
        if(ones!="") converted+=" "+ones;
        return converted;
    }
};