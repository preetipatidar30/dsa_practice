class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty()) return {};
        
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        int row = 0, col = 0;
        bool up = true;
        
        while (result.size() < m * n) {
            result.push_back(mat[row][col]);
            
            if (up) {
                // Moving up-right
                if (col == n - 1) {
                    row++;
                    up = false;
                } else if (row == 0) {
                    col++;
                    up = false;
                } else {
                    row--;
                    col++;
                }
            } else {
                // Moving down-left
                if (row == m - 1) {
                    col++;
                    up = true;
                } else if (col == 0) {
                    row++;
                    up = true;
                } else {
                    row++;
                    col--;
                }
            }
        }
        
        return result;
    }
};