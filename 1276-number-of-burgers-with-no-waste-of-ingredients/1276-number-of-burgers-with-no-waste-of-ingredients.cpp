class Solution {
public:
    // Can be solved in O(N) using a simple while loop
    // I am solving in O(1) T.C. using Maths
    vector<int> numOfBurgers(int ts, int cs) {
        int j=(ts-cs*2)/2; // The required no. of jumbo burgers to utilize all tomato slices
        return (j<0 || j*4+(cs-j)*2!=ts || cs-j<0)?vector<int>{}:vector<int>{j,cs-j};
    }
};