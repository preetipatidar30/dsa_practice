class Solution {
public:
    int reverseBits(int n) {
        vector<int>arr;
        int a=n;
        while(a > 0){
            arr.push_back(a % 2);
            a = a / 2;
        }
        while(arr.size() < 32){
            arr.push_back(0);
        }
        int ans=0;
               for(int i = 0; i < 32; i++){
            if(arr[i] == 1){
                ans += (1 << (31 - i));
            }
        }
        return ans;
        

        
    }
};