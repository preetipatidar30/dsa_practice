class Solution {
public:
bool ispalin(string s){
    int n=s.size();
    int l=0;
    int r=n-1;
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
void getall(string s,vector<string>&curr,vector<vector<string>> &ans){
    if(s.size()==0){
        ans.push_back(curr);
        return;
    }
    int n=s.size();
    for(int i=0;i<n;i++){
        string part=s.substr(0,i+1);
        if(ispalin(part)){
            curr.push_back(part);
            getall(s.substr(i+1),curr,ans);
            curr.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string> >ans;
        getall(s,curr,ans);
        return ans;
        
        
    }
};