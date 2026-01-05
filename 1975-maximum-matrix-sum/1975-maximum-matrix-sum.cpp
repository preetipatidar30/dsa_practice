class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negCount = 0;
        int mini = INT_MAX;

        for (auto &row : matrix) {
            for (int val : row) {
                if (val < 0) negCount++;
                sum += abs(val);
                mini = min(mini, abs(val));
            }
        }

        // If odd negatives, one smallest must remain negative
        if (negCount % 2 == 1) {
            sum -= 2LL * mini;
        }

        return sum;
    }
};
