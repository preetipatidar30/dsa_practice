class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int n=s.size();
     int maxlen=0;
        unordered_map<char, int> ans;
        int l = 0;

        for (int r = 0; r < n; r++) {
            if (ans.find(s[r]) != ans.end() && ans[s[r]] >= l) {
                l = ans[s[r]] + 1;
            }

            ans[s[r]] = r;
            int len = r - l + 1;
            maxlen = max(len, maxlen);
        }

        return maxlen;
    }
};