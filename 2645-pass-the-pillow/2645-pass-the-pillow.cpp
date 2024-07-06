class Solution {
public:
    int passThePillow(int n, int time) {
        bool dir=true;
        int person=1;
        do {
            if(dir) person++;
            else person--;
            time--;
            if(person==1 || person==n) dir=!dir;
        } while(time);
        return person;
    }
};