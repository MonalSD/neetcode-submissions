class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int maxMinutes =0;
        queue<pair<int,int>> q;
        int ROW = grid.size();
        int COL = grid[0].size();
        vector<vector<bool>> visit(ROW,vector<bool>(COL,false));
        
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            if(r-1>=0 && grid[r-1][c]==1){
                q.push({r-1,c});
                grid[r-1][c] = grid[r][c]-1;
                maxMinutes = min(maxMinutes,grid[r-1][c]);
            }
            if(c+1<COL && grid[r][c+1]==1){
                q.push({r,c+1});
                grid[r][c+1] = grid[r][c]-1;
                maxMinutes = min(maxMinutes,grid[r][c+1]);
            }
            if(r+1<ROW && grid[r+1][c]==1){
                q.push({r+1,c});
                grid[r+1][c] = grid[r][c]-1;
                maxMinutes = min(maxMinutes,grid[r+1][c]);
            }
            if(c-1>=0 && grid[r][c-1]==1){
                q.push({r,c-1});
                grid[r][c-1] = grid[r][c]-1;
                maxMinutes = min(maxMinutes,grid[r][c-1]);
            }
            
        }
        
        //for fresh fruits left
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return abs(maxMinutes);
        
        
    }
};
