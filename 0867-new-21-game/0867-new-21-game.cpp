class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
          if (k == 0) return 1.0; // If k=0, Alice doesn't draw, so score is 0 (within [0, n]).
        if (n >= k + maxPts - 1) return 1.0; // If n is large enough, all outcomes are valid.

        vector<double> dp(n + 1);
        dp[0] = 1.0;
        double windowSum = 1.0; // Sum of dp[j] for j in [max(0, i-maxPts), i-1] where j < k
        double result = 0.0;

        for (int i = 1; i <= n; i++) {
            // dp[i] = sum of dp[i-j] / maxPts for j from 1 to maxPts where i-j >= 0 and i-j < k
            dp[i] = windowSum / maxPts;

            // Update windowSum for the next iteration
            if (i < k) {
                windowSum += dp[i]; // Add dp[i] for the next window
            }
            if (i >= maxPts && i - maxPts < k) {
                windowSum -= dp[i - maxPts]; // Remove dp[i-maxPts] if it's within bounds
            }
            if (i >= k) {
                result += dp[i]; // Accumulate probabilities for i >= k
            }
        }

        return result;
    }
};