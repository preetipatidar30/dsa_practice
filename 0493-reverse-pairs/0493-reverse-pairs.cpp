class Solution {
public:
int countpairs(vector<int>& nums,int low,int mid,int high){
    int right=mid+1;
    int cnt=0;
    for(int i=low;i<=mid;i++){
        while(right<=high && nums[i]>(2LL*nums[right])){
            right++;
        }
        cnt+=right-(mid+1);
    }


    return cnt;
}
void merge(vector<int>& nums,int low,int mid,int high){
    int left=low;
    int right=mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left++;
        }else{
            temp.push_back(nums[right]);
            right++;
        }

    }
    while(left<=mid){
        temp.push_back(nums[left]);
        left++;

    }
    while(right<=high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        nums[i]=temp[i-low];
    }
   
}
int mergeS(vector<int>& nums,int low,int high){
    int cnt=0;
    if(low<high){
       int mid=(low+high)/2;
        cnt+=mergeS(nums,low,mid);
        cnt+=mergeS(nums,mid+1,high);
        cnt+=countpairs(nums,low,mid,high);
        merge(nums,low,mid,high);

    }
    return cnt;
}
    int reversePairs(vector<int>& nums) {
      int n=nums.size();
      int cnt=0;
      cnt=mergeS(nums,0,n-1);
        return cnt;
    }
};