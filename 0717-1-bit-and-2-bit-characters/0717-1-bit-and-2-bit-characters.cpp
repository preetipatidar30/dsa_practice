class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
      int n=bits.size();
      if(bits[n-1]==1){
        return false;
      }
      int i=0;
     while(i<n-1){
        if(bits[i]==1 && i==n-2){
            return false;
        }
        if(bits[i]==0){
            i++;
        }else{
            i+=2;
        }
       
     }
     return true;
    }
};