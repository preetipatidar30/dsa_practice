class Solution {
public:
set<vector<int> >s;
void helper(vector<int>&candidates,int i,vector<int>& comb,vector<vector<int>>&ans,int target){
    int n=candidates.size();
    if(i==n ||target<0){
        return;
            }
if(target==0){
  if(s.find(comb)==s.end()){
      ans.push_back(comb);
      s.insert(comb);
    return;
  }
}

    comb.push_back(candidates[i]);
    helper(candidates,i+1,comb,ans,target-candidates[i]);
     
    helper(candidates,i,comb,ans,target-candidates[i]);
    comb.pop_back();
    
    helper(candidates,i+1,comb,ans,target);
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) { 
     vector<int>comb;
     vector<vector<int>> ans;
     
    helper(candidates,0,comb,ans,target);
    return ans;


    }


        
    
};