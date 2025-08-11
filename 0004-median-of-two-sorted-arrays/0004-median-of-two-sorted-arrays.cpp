class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n=nums1.size();
       int m=nums2.size();
       int l=0;
       while(l<n && n!=0&&m!=0){
        if(nums2[0]<nums1[l]){
            swap(nums2[0],nums1[l]);
        }
        sort(nums2.begin(),nums2.end());
        l++;
       }
       int s=(m+n)/2;
       if(s<n){
        if((n+m)%2==1){
            return nums1[s];

        }else{
            return double(nums1[s-1]+nums1[s])/2;
        }
       }else{
        if((n+m)%2==1){
            return nums2[s-n];
        }else{
            if(s==n){
                return double(nums1[n-1]+nums2[s-n])/2;
            }else{
                return double(nums2[s-n-1]+nums2[s-n])/2;
            }
        }
       }
     

        
    }
};