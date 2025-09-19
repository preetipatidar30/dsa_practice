class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int count =1;
        int n=pairs.size();
        if(n<2){
            return n;
        }
        int last=pairs[0][1];
        int i=1;
        while(i<n){
            if(last<pairs[i][0]){
                last=pairs[i][1];
                count++;
            }
            i++;
        }
        return count;
    
    }
};