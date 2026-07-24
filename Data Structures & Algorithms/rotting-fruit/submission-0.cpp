class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                else  if(grid[i][j]==1) fresh++;
            }
        }
        if(!fresh) return 0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int count=0;
        while(!q.empty() && fresh>0){
            int sz = q.size();
            while(sz--){
            auto[r,c]=q.front();
            q.pop();
            
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0&& nr<n&& nc>=0&& nc<m&&  grid[nr][nc] == 1&& !vis[nr][nc]){
                    vis[nr][nc]=true;
                    fresh--;
                    q.push({nr,nc});
                }
            }
            }
            count++;
        }
        return (fresh == 0) ?count: -1;;
    }
};
