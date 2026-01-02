class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<pair<int,int>> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp.push_back({nums[i],i});

        }
        sort(mp.begin(),mp.end());
        int r=n-1;
        int l=0;
        while(l<r){
            int sum=mp[l].first + mp[r].first;
            if(sum==target){
                return {mp[l].second,mp[r].second};
            }else if(sum<target){
                l++;
            }else{
                r--;
            }
        }
        return {-1,-1};
        
    }
};