class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size(),minDiff=INT_MAX;
        vector<int> minuteFormat;
        for(string timePoint:timePoints) minuteFormat.push_back(stoi(timePoint.substr(0,2))*60+stoi(timePoint.substr(3,2)));
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                int diff=min(abs(minuteFormat[i]-minuteFormat[j]),1440-abs(minuteFormat[i]-minuteFormat[j]));
                if(diff<minDiff) minDiff=diff;
            }
        }
        return minDiff;
    }
};