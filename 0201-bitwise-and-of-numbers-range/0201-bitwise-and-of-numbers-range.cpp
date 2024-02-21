class Solution {
public:
    // 2 consecutive numbers would only differ in the LSB
    // Bitwise AND-ing such pairs of numbers would only yield the smaller number
    int rangeBitwiseAnd(int left, int right) {
        while(left<right) right&=(right-1);
        return right;
    }
};