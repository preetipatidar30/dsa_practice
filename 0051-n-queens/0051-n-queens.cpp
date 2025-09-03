class Solution {
public:
bool iss( vector<string>&b,vector<vector<string>> &ans,int row,int n,int j){
    for(int i=0;i<n;i++){
       if(b[row][i]=='Q'){
       return false;
       }
    }
     for(int i=0;i<n;i++){
     if(  b[i][j]=='Q'){
       return false;
       }
    }
     for (int i = row, k = j; i >= 0 && k >= 0; i--, k--) {
            if (b[i][k] == 'Q') return false;
        }
        // check upper right diagonal
        for (int i = row, k = j; i >= 0 && k < n; i--, k++) {
            if (b[i][k] == 'Q') return false;
        }
   
    return true;
}
void getQ(vector<string>&b,vector<vector<string>> &ans,int row,int n){
    if(row==n){
        ans.push_back(b);
        return;
    }
    for(int j=0;j<n;j++){
        if(iss(b,ans,row,n,j)){
            b[row][j]='Q';
            getQ(b,ans,row+1,n);
            b[row][j]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string>b(n,string(n,'.'));
        vector<vector<string>> ans;
        getQ(b,ans,0,n);
        return ans;

        
    }
};