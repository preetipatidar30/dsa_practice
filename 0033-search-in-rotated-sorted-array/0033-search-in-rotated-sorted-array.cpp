class Solution {
public:
    int search(vector<int>& nums, int target) {
       int a=-1;
       int n=nums.size();
       for(int i=0;i<n;i++){
        if(nums[i]==target){
            a=i;
        }
       }
        
       return a;
       }
};