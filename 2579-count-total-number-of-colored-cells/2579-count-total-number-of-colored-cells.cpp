class Solution {
public:
    long long coloredCells(int n) {
        // The series is as follows: 1 + 4 + 8 + 12 + ... up to n terms
        // This is 1 + (4 + 8 + 12 + ... up to n - 1 terms) = 1 + 4 (1 + 2 + 3 + ... n - 1)
        // Sn = 1 + 4(n - 1)(n - 1 + 1) / 2 => Sn = 1 + 2n(n - 1)
        // The sum of the series (Sn) can be expressed as 1 + 2 * n * (n - 1)
        return 1+(long long)2*n*(n-1);
    }
};
