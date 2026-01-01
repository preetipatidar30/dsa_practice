class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       reverse(digits.begin(),digits.end());
       int sum=1;
       int idx=0;
       int i=0;
       while(i<digits.size()){
        if(digits[i]+1  < 10){
            digits[i]=digits[i]+1;
            sum=0;
            break;
        }else{
            digits[i]=0;
            idx++;

        }
        i++;
       }
       if(sum>0){
        digits.push_back(1);
       }
       reverse(digits.begin(),digits.end());
       
      return digits;
        
    }
};