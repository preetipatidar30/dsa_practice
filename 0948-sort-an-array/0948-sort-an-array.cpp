class Solution {
public:
void merge(vector<int>&nums,int l,int r){
    int mid=(l+r)/2;
    int l1=l;
    int l2=mid+1;
    vector<int> temp;
    while(l1<=mid&&l2<=r){
        if(nums[l1]<nums[l2]){
            temp.push_back(nums[l1]);
            l1++;
        }else{
            temp.push_back(nums[l2]);
            l2++;
        }

    }
    while(l1<=mid){
        temp.push_back(nums[l1]);
        l1++;
    }
    while(l2<=r){
        temp.push_back(nums[l2]);
        l2++;
    }
    for(int i=0;i<temp.size();i++){
        nums[l+i]=temp[i];
    }
}
void mergesort(vector<int>&nums,int l,int r){
    int mid=(l+r)/2;
    if(l>=r){
        return;
    }
    mergesort(nums,l,mid);
    mergesort(nums,mid+1,r);
    merge(nums,l,r);
}
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        return nums;
        
    }
};