class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        
        // Check if n is a power of 2 (has only one bit set)
        if ((n & (n - 1)) != 0) return false;
        
        // Check if the set bit is at an even position (0-based index: 0, 2, 4, ...)
        return (n & 0x55555555) != 0;
    }
};