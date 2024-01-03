class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int emitters=0,beams=0;
        for(string floor:bank) {
            int devices=0;
            for(char c:floor) if(c=='1') devices++;
            if(devices>0) {
                beams+=devices*emitters;
                emitters=devices;
            }
        }
        return beams;
    }
};