class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=1;
        int r=n-2;
        while(l<=r){
          int m=(l+r)/2;
          if(arr[m-1]<arr[m]&&arr[m+1]<arr[m]){
            return m;
          }else if(arr[m-1]<arr[m]){
            l=m+1;

          }else{
            r=m-1;
          }
        }
        return -1;
    }
};