class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0; // Total number of zero-filled subarrays
        long long num = 0; // Length of current sequence of zeros
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                num++; // Increment length of current zero sequence
                ans += num; // Add number of subarrays ending at i
            } else {
                num = 0; // Reset sequence length when non-zero is encountered
            }
        }
        
        return ans;
    }
};