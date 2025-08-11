class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n=nums1.size();
       int m=nums2.size();
       vector<int> ans;
       int l=0 ,r=0;
       while(l<n && r<m){
        if(nums1[l]<=nums2[r]){
            ans.push_back(nums1[l]);
            l++;
        }else{
            ans.push_back(nums2[r]);
            r++;
        }
       }
       while(l<n){
        ans.push_back(nums1[l]);
        l++;
       }
       while(r<m){
        ans.push_back(nums2[r]);
        r++;
       }
       int s=m+n;
       if(s%2==1){
        return ans[s/2];
       }else{
        
       return double(ans[s/2]+ans[(s/2)-1])/2;

       }

        
    }
};