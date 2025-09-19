class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;

    if(n<2){
        return ans;
    }

    for(int i=1;i<n;i++){
        for(int j=2;j<=n;j++){
         if(i<j && __gcd(i, j) == 1){
               string str="";
            str+=to_string(i);
            str+="/";
            str+=to_string(j);
            ans.push_back(str);

         }
        }
    }
    return ans;
        
    }
};