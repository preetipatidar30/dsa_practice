class Solution {
public:
    int smallestNumber(int n) {
        if(n==1 |n==0){
            return 1;
        }
      int m=1;
      while(m<=n){
        m=m*2;
      }
      return m-1;
    }
};