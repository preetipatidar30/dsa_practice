class Solution {
    private:
    void dfs(vector<vector<int>>& image,vector<vector<int>>&ans, int sr, int sc, int incol, int color,int delr[],int delc[]){
        ans[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();

        for(int i=0;i<4;i++){
            int row=sr+delr[i];
            int col=sc +delc[i];
            if(row>=0&&row<n&&col>=0&&col<=m && image[row][col]==incol && ans[row][col]!=color){
                
            dfs(image,ans,row,col,incol,color,delr,delc);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int incol=image[sr][sc];
     vector<vector<int>> ans=image;
     int delr[]={-1,0,+1,0};
     int delc[]={0,-1,0,+1};
     dfs(image,ans,sr,sc,incol,color,delr,delc);
     return ans;

    }
};