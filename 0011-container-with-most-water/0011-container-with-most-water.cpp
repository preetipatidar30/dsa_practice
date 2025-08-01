class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxw=0;
        int l=0;
        int r=n -1;
        while(l<r){
            int h= min(height[l],height[r]);
            int w= r-l;
            int wa =h*w;
            maxw=max(maxw,wa);
            if(height[l]<=height[r]){
                l++;

            }else{
                r--;
            }
            
                    }
                    return maxw;
    }
};