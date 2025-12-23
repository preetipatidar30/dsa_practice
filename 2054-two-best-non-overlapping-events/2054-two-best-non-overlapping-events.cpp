class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        // 1. Sort by start time
        sort(events.begin(), events.end());

        // 2. suffixMax[i] = max value from i to end
        vector<int> suffixMax(n);
        suffixMax[n-1] = events[n-1][2];

        for (int i = n-2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i+1], events[i][2]);
        }

        int ans = 0;

        // 3. For each event, binary search next valid event
        for (int i = 0; i < n; i++) {
            int curr = events[i][2];
            int lo = i + 1, hi = n - 1, idx = -1;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (events[mid][0] > events[i][1]) { // inclusive end
                    idx = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            if (idx != -1) {
                curr += suffixMax[idx];
            }

            ans = max(ans, curr);
        }

        return ans;
    }
};
