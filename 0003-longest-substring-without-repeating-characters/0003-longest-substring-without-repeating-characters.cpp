class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int n=s.size();
     int maxlen=0;
     for(int i=0;i<n;i++){
        unordered_map<char,int> ans;
        for(int j=i;j<n;j++){
           
            if(ans[s[j]]>0){
                break;
            }
             ans[s[j]]++;
            int len=j-i+1;
            maxlen=max(maxlen,len);

        }
     }
     return maxlen;
    }
};