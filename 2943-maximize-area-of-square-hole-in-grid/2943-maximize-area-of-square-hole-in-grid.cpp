class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxH = getMaxGap(hBars);
        int maxV = getMaxGap(vBars);

        int side = min(maxH, maxV);
        return side * side;
    }

private:
    int getMaxGap(vector<int>& bars) {
        sort(bars.begin(), bars.end());

        int maxLen = 1, curr = 1;

        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1) {
                curr++;
            } else {
                curr = 1;
            }
            maxLen = max(maxLen, curr);
        }

        // +1 because removing k consecutive bars creates k+1 gap
        return maxLen + 1;
    }
};
