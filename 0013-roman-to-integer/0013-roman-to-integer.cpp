class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> roman={
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
            
        };
        int n=s.length();
        if(n==0){
            return 0;
        }
        int num=roman[s[n-1]];
        for(int i=n-2;i>=0;i--){
            if(roman[s[i]]>=roman[s[i+1]]){
                num+=roman[s[i]];
            }else{
                num-=roman[s[i]];
            }
        }
        return num;
    }

       
};