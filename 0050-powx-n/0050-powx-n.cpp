class Solution {
public:
    double myPow(double x, int n) {
         double ans=1;
         double a=x;
         int sign=0;
         if(n==0|| x==1){
            return 1;
         }
         
         
         if(x==-1){
            if(n%2==0){
                return 1;
            }else{
                return -1;
            }
         }
         if(n<(-10000)){
            return 0;
         }
         if(n<0){
            n=(-n);
            sign=1;

         }

         while(n>1){
            if(n%2==1){
                ans*=a;
                n=n-1;

            }else{
                n=n/2;
                a=(a*a);
            }

         }
         ans*=a;
         if(sign==1){
            ans=(1/ans);
         }
         return ans;
    }
};