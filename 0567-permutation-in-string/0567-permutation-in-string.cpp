class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        int frq[26]={0};
        for(int i=0;i<n;i++){
            frq[s1[i]-'a']++;
        }
        for(int i=0;i<=m-n;i++){
            int curr[26]={0};
            for(int j=i;j<i+n;j++){
                curr[s2[j]-'a']++;
            }
            bool currt=true;
            for(int k=0;k<26;k++){
                if(curr[k]!=frq[k]){
                    currt=false;
                    break;
                }


            }
            if(currt==true){
                return true;
            }
        }
        return false;
    }
};