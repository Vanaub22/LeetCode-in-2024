class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour==12) hour=0;
        double hour_pos=30*(hour+(double)minutes/60),res=abs(hour_pos-minutes*6);
        return res>180?360-res:res;
    }
};