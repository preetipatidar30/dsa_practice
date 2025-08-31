class Solution {
public:
    // Helper function to expand around center and return length of palindrome
    int expandAroundCenter(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Length of palindrome = right - left - 1
        return right - left - 1;
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
        int start = 0; // Start index of longest palindrome
        int maxLen = 1; // Length of longest palindrome (at least 1 for single char)
        
        for (int i = 0; i < n; i++) {
            // Check for odd-length palindromes (center at i)
            int len1 = expandAroundCenter(s, i, i);
            // Check for even-length palindromes (center between i and i+1)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            // Update if we find a longer palindrome
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2; // Calculate start index
            }
        }
        
        return s.substr(start, maxLen);
    }
};