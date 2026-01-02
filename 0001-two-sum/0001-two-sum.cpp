class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> mp;
      for(int i=0;i<nums.size();i++){
        int cc=target-nums[i];
        if(mp.find(cc)!=mp.end()){
            return {mp[cc],i};
        }
        mp[nums[i]]=i;
      }
      return {-1,-1};

        
    }
};