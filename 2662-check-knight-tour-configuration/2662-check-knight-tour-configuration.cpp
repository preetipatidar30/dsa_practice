class Solution {
public:
bool isvalid(vector<vector<int>>&grid,int n,int row,int col,int exp){

  
    if(row<0||col<0||row>=n||col>=n||grid[row][col]!=exp){
        return false;
    
    }
      if(exp==(n*n)-1){
        return true;
    }
    int a1=isvalid(grid,n,row+2,col+1,exp+1);
    
    int a2=isvalid(grid,n,row+2,col-1,exp+1);
    
    int a3=isvalid(grid,n,row-2,col+1,exp+1);
    
    int a4=isvalid(grid,n,row-2,col-1,exp+1);
    
    int a5=isvalid(grid,n,row+1,col+2,exp+1);
    
    int a6=isvalid(grid,n,row+1,col-2,exp+1);
    
    int a7=isvalid(grid,n,row-1,col-2,exp+1);
    
    int a8=isvalid(grid,n,row-1,col+2,exp+1);
    return a1||a2||a3||a4||a5||a6||a7||a8;
}
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        return isvalid(grid,n,0,0,0);
    }
};