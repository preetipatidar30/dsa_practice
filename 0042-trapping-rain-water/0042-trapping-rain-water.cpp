class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
     int count =0; 
     int l=0;
     int r=n-1;
     int left=0;
     int right=0;
     while(l<r){
        left=max(height[l],left);
        right=max(height[r],right);
        if(left<=right){
            count+= min(left,right) - height[l];
            l++;
        }else{
            count+= min(left,right)-height[r];
            r--;
        }
     }

return count;

        


        
    }
};