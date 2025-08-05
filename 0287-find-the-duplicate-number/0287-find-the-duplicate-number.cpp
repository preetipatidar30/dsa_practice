class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>ans;
        int n =nums.size();
        for(int i=0;i<n;i++){
            ans[nums[i]]++;
        }
        for(auto it: ans){
            if(it.second>1){
                return it.first;
            }
        }
        return -1;
    }
};