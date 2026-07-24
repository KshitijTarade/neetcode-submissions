class Solution {
public:
    int n;
    int m;
    vector<vector<int>> ans;
 
     void dfs1(int i,int j, vector<vector<int>>& grid,vector<vector<bool>>& pac){
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nc>=0 && nc<m && nr<n && nr>=0 && grid[nr][nc]>=grid[i][j]&& pac[nr][nc]!=true){
                pac[nr][nc]=true;  
                dfs1(nr,nc,grid,pac);
            }
        }
        return ;
    }
    void dfs2(int i,int j, vector<vector<int>>& grid,vector<vector<bool>>& aat){
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nc>=0 && nc<m && nr<n && nr>=0 && grid[nr][nc]>=grid[i][j] && aat[nr][nc]!=true){
                  aat[nr][nc]=true;
                  dfs2(nr,nc,grid,aat);
            }
        }
        return ;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>> pac(n,vector<bool>(m,0));
        vector<vector<bool>> aat(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            pac[i][0]=true;
            aat[i][m-1]=true;
        }
        for(int j=0;j<m;j++){
            pac[0][j]=true;
            aat[n-1][j]=true;
        }
        for(int i=0;i<n;i++){
                dfs1(i,0,grid,pac);
                dfs2(i,m-1,grid,aat);
        }
        for(int j=0;j<m;j++){
                dfs1(0,j,grid,pac);
                dfs2(n-1,j,grid,aat);
        }
        vector<int>v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j]&&aat[i][j]){
                    v.push_back(i);
                    v.push_back(j);
                    ans.push_back(v);
                    v.clear();
                }
            }
        }
        return ans;
    }
};
