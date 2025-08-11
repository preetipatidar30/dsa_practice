class Solution {
public:
bool isalphanumeric(char ch){
    if(ch<='9'&&ch>='0'){
        return true;
    }
    if(tolower(ch)<='z' && tolower(ch)>='a'){
        return true;
    }
    return false;
}
    bool isPalindrome(string s) {
        string s2="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isalphanumeric(s[i])){
                s2+= tolower(s[i]);
            }
        }
        int m=s2.size();
        int l=0;
        int r=m-1;
        while(l<=r){
            if(s2[l]!=s2[r]){
                return false;
                break;
            }
            l++;
            r--;
        }
        return true;
    }
};