class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // edge
        if(buildings.empty()) return 0;

        unordered_map<int, pair<int,int>> rowRange; // row -> {minCol, maxCol}
        unordered_map<int, pair<int,int>> colRange; // col -> {minRow, maxRow}

        // initialize ranges
        for(auto &b : buildings){
            int r = b[0], c = b[1];
            if(rowRange.find(r) == rowRange.end()){
                rowRange[r] = {c, c};
            } else {
                rowRange[r].first  = min(rowRange[r].first, c);
                rowRange[r].second = max(rowRange[r].second, c);
            }

            if(colRange.find(c) == colRange.end()){
                colRange[c] = {r, r};
            } else {
                colRange[c].first  = min(colRange[c].first, r);
                colRange[c].second = max(colRange[c].second, r);
            }
        }

        int count = 0;
        for(int idx = 0; idx < (int)buildings.size(); ++idx){
            int r = buildings[idx][0];
            int c = buildings[idx][1];

            auto &rRange = rowRange[r]; // guaranteed to exist
            auto &cRange = colRange[c]; // guaranteed to exist

            bool left  = (rRange.first < c);   // some column in same row with col < c
            bool right = (rRange.second > c);  // some column in same row with col > c
            bool above = (cRange.first < r);   // some row in same col with row < r
            bool below = (cRange.second > r);  // some row in same col with row > r

            if(left && right && above && below) ++count;
        }
        return count;
    }
};
