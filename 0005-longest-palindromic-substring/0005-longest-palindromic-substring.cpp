class Solution {
public:
       string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int n = s.size();
        int start = 0, maxLength = 1; // Initialize to return at least one character
        
        // Helper function to expand around center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            // Return length and start index of palindrome
            int len = right - left - 1;
            return pair<int, int>{len, left + 1};
        };
        
        // Check all possible centers
        for (int i = 0; i < n; i++) {
            // Odd-length palindrome (center at i)
            auto [len1, start1] = expandAroundCenter(i, i);
            if (len1 > maxLength) {
                maxLength = len1;
                start = start1;
            }
            
            // Even-length palindrome (center between i and i+1)
            if (i < n - 1) {
                auto [len2, start2] = expandAroundCenter(i, i + 1);
                if (len2 > maxLength) {
                    maxLength = len2;
                    start = start2;
                }
            }
        }
        
        return s.substr(start, maxLength);
       
    }
};