class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls){
    vector<vector<int> >vis(m,vector<int>(n,0));

    for(int i=0;i<walls.size();i++){
        vis[walls[i][0]][walls[i][1]]=10;
    }
    for(int i=0;i<guards.size();i++){
        int r=guards[i][0];
        int c=guards[i][1];
        vis[r][c]=20;
    }
      for(int i =0;i<m;i++){
        bool seen=false;
        for(int j=0;j<n;j++){
            if(vis[i][j]==20){
                seen=true;
            }else if(vis[i][j]==10){
                seen=false;
            }else if(seen ==true){
                vis[i][j]=1;
            }
        }
      }
      for(int i =0;i<m;i++){
        bool seen=false;
        for(int j=n-1;j>=0;j--){
            if(vis[i][j]==20){
                seen=true;
            }else if(vis[i][j]==10){
                seen=false;
            }else if(seen ==true){
                vis[i][j]=1;
            }
        }
      }
      for (int j = 0; j < n; j++) {
            bool seen = false;
            for (int i = 0; i < m; i++) {
                if (vis[i][j] == 20) seen = true;
                else if (vis[i][j] == 10) seen = false;
                else if (seen) vis[i][j] = 1;
            }
        }

        // ↑ (bottom to top)
        for (int j = 0; j < n; j++) {
            bool seen = false;
            for (int i = m - 1; i >= 0; i--) {
                if (vis[i][j] == 20) seen = true;
                else if (vis[i][j] == 10) seen = false;
                else if (seen) vis[i][j] = 1;
            }
        }
      
    
    int count =0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]==0){
                count++;
            }
        }
    }
    return count;


    }
  
};