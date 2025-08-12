class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
         int n=s.size();
         vector<int> hh(26);
         for(int i=0;i<n;i++){
            hh[s[i]-'a']++;

         }
         for(int i=0;i<n;i++){
            --hh[t[i]-'a'];
            if(hh[t[i]-'a'] <0){
                return false;
            }
         }
      
        return true;
    }
};