class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        // Convert int to sorted string of digits
        auto sortedDigits = [](int x) {
            string s = to_string(x);
            sort(s.begin(), s.end());
            return s;
        };

        string target = sortedDigits(n);
        unordered_set<string> powerOf2Forms;

        // Precompute all powers of 2 up to 1e9
        for (long long i = 1; i <= 1e9; i <<= 1) {
            powerOf2Forms.insert(sortedDigits(i));
        }

        return powerOf2Forms.count(target) > 0;
 

    }
};