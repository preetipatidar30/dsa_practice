class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(nums[i]==2){
                ans.push_back(-1);
            }else{
                int count =1;
                int a=nums[i];
                while(a%2==1 && a>0){
                    count=count*2;
                    a/=2;
                }
                count=count/2;
                int anss=nums[i]-count;
                ans.push_back(anss);

            }

            

        }
        return ans;
        
    }
};