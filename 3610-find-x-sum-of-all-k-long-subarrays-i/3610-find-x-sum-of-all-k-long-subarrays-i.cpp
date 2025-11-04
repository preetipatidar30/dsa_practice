class Solution {
public:
  static bool comparePairs(const pair<int,int>& a, const pair<int,int>& b) {
        if (a.second == b.second)
            return a.first > b.first; // higher number first when freq equal
        return a.second > b.second;   // higher frequency first
    }

    void sort_by_sec(vector<pair<int, int>> &freq) {
        sort(freq.begin(), freq.end(), comparePairs);
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
         int n=nums.size();
         int r=0;
         vector<int> ans;
         while(r<=n-k){
            unordered_map<int, int> cnt;
            for(int i=r;i<r+k;i++){
                cnt[nums[i]]++;
            }
            vector<pair<int,int>> freq(cnt.begin(),cnt.end());
            // sorting
          sort_by_sec(freq);
              int xsum = 0;
            for (int j = 0; j < x && j < freq.size(); ++j) {
                xsum += freq[j].first * freq[j].second;
            }
            ans.push_back(xsum);
            r++;


         }
         return ans;
    }
};