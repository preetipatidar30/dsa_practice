class Solution {
public:
    bool hasAlternatingBits(int n) {
        int a=n;
        int bit;
        if(n==0 ||n==1){
            return true;

        }
        if(a%2==0){
            bit=0;
        }else{
            bit=1;
        }
        a=a/2;
        
        while(a>0){
            if(a%2==bit){
                return false;
            }
            bit=a%2;
            a=a/2;

            
        }
    return true;
        
    }
};