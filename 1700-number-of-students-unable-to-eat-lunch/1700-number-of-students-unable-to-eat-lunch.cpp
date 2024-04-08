// Intuitive implementation using stack and queue (Not optimal)
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> sw;
        queue<int> q;
        int n=students.size(),qsize;
        for(int i=n-1;i>=0;i--) sw.push(sandwiches[i]);
        for(int student:students) q.push(student);
        bool pref;
        do {
            pref=false;
            qsize=q.size();
            if(!qsize) return 0; // All students have been served
            for(int i=0;i<qsize;i++) {
                if(sw.top()==q.front()) {
                    sw.pop(); // Sandwich given away
                    pref=true; // At least one student was satisfied in this iteration
                }
                else q.push(q.front()); // Student moves to the end of the queue
                q.pop(); // Student leaves
            }
        } while(pref);
        return qsize;
    }
};