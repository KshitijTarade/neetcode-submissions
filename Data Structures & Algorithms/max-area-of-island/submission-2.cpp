class Solution {
public:
     int ans;
     int n;
     int m;
       void dfs(int i, int j, vector<vector<int>>& grid,vector<vector<bool>> &vis,int& count){
        vis[i][j]=true;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
                 if(nr>=0&& nr<n&& nc>=0&& nc<m&& grid[nr][nc]==1 && !vis[nr][nc]){
                    count++;
                    dfs(nr,nc,grid,vis,count);
                }
        }
        ans=max(ans,count);
        return;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ans=INT_MIN;
        n=grid.size();
        int count=0;
        m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int count=1;
                    dfs(i,j,grid,vis,count);
                }
            }
        }
        return (ans<0)?0:ans;
    }
};
