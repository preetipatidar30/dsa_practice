class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int maxDiagonal = 0;
        int maxArea = 0;
        
        for (int[] rect : dimensions) {
            int a = rect[0];
            int b = rect[1];
            int diagonal = a * a + b * b; // Calculate diagonal^2 (no need for sqrt)
            int area = a * b;

            if (diagonal > maxDiagonal || (diagonal == maxDiagonal && area > maxArea)) {
                maxDiagonal = diagonal;
                maxArea = area;
            }
        }
        
        return maxArea;
    }
}