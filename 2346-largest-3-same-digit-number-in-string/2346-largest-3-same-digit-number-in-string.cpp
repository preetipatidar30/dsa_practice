class Solution {
public:
    string largestGoodInteger(string num) {
                string ans = "";
        for (int i = 0; i + 2 < num.size(); i++) {
            // Check if three consecutive digits are equal
            if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
                string curr = num.substr(i, 3);
                ans = max(ans, curr); // lexicographic max works for digits
            }
        }
        return ans;
        
    }
};