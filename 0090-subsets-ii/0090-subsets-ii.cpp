class Solution {
public:
void fsubset(vector<int>& nums,vector<int>&curr,vector<vector<int>>& res,int index){
 res.push_back(curr);

        for (int i = index; i < nums.size(); ++i) {
            if (i > index && nums[i] == nums[i - 1]) continue;

            curr.push_back(nums[i]);
            fsubset(nums, curr, res, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>curr;
        vector<vector<int>> res;
        fsubset(nums,curr,res,0);
        return res;
        
    }
};