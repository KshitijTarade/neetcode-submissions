class Solution {
public:
    int n;
    int m;
    
    void dfs(int i, int j, vector<vector<char>>& grid,vector<vector<bool>> &vis ){
        vis[i][j]=true;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
                 if(nr>=0&& nr<n&& nc>=0&& nc<m&& grid[nr][nc]=='1' && !vis[nr][nc]){
                    dfs(nr,nc,grid,vis);
                }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        int count=0;
        m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
       
    }
};
