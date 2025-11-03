class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
       int n=colors.length();
       int l=0;
       if(n<=1){
        return 0;
       }
       int r=1;
       char ch=colors[l];
       int sum=neededTime[l];
       int maxi=neededTime[l];
       int count=0;
       while(r<n){
        if(ch==colors[r]){
            sum+=neededTime[r];
            maxi=max(maxi, neededTime[r]);
            r++;
        }else{
            count+= sum-maxi;
            ch=colors[r];
            sum=neededTime[r];
            maxi=neededTime[r];
            l=r;
            r++;
            }
       }
       count+=sum-maxi;
       return count;

        
    }
};