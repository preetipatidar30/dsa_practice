class Solution {
public:
  
set<vector<int> >s;
void helper(vector<int>&candidates,int i,vector<int>& comb,vector<vector<int>>&ans,int target){
    int n=candidates.size();
      if (target == 0) {
            ans.push_back(comb);
            return;
        }
    if(i==n ||target<0){
        return;
            }


    comb.push_back(candidates[i]);
    helper(candidates,i+1,comb,ans,target-candidates[i]);
    comb.pop_back();
     while (i + 1 < n && candidates[i] == candidates[i + 1]) i++;
 
        helper(candidates, i+1, comb, ans, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) { 
     vector<int>comb;
     vector<vector<int>> ans;
     sort(candidates.begin(), candidates.end());
     
    helper(candidates,0,comb,ans,target);
    return ans;


    }

};