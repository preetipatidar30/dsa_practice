class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
      int n=nums.size();
      int i=0;
      int curr=-1;
      while(i<n){
        if(nums[i]==1){
           if(curr != -1 && i - curr - 1 < k) {
                    return false;
                }
                curr=i;
            }
        
        i++;

      }
      return true;
    }
};