class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            if(arr[l]<=arr[l+1]){
                l++;
            }else{
                return l;
                break;
            }
            if(arr[r]<=arr[r-1]){
                r--;
            }else{
                return r;
                break;
            }
        }
        return -1;
    }
};