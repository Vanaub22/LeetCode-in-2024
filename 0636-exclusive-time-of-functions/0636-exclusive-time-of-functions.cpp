// Defining a custom class for the Logs
class Log {
public:
    int id,ts;
    string status;
    Log(string& log) {
        stringstream ss(log);
        string x;
        getline(ss,x,':');
        this->id=stoi(x);
        getline(ss,this->status,':');
        getline(ss,x);
        this->ts=stoi(x);
    }
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<Log> callStack;
        vector<int> excTime(n);
        for(auto& log:logs) {
            Log L=*new Log(log);
            if(L.status=="start") callStack.push(L);
            else {
                auto lastLog=callStack.top();
                int runningTime;
                if(lastLog.id==L.id) {
                    runningTime=L.ts-lastLog.ts+1;
                    excTime[lastLog.id]+=runningTime;
                    callStack.pop();
                }
                // Subtracting nested fn. call running time from the outer fn.
                if(!callStack.empty()) excTime[callStack.top().id]-=runningTime;
            }
        }
        return excTime;
    }
};