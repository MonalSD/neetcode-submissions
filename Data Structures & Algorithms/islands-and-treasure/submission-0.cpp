class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        queue<pair<int,int>> q;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                     q.push({i,j});
                }   
            }
        }
        
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;
            visited[r][c]=true;
            if(r-1>=0 && visited[r-1][c]==false && grid[r-1][c]==2147483647){
                q.push({r-1,c});
                grid[r-1][c] = grid[r][c]+1;
            }  
            if(c+1<grid[0].size() && visited[r][c+1]==false && grid[r][c+1]==2147483647){
                q.push({r,c+1});
                grid[r][c+1]= grid[r][c]+1;
            }
            if(r+1<grid.size() && visited[r+1][c]==false && grid[r+1][c]==2147483647){
                q.push({r+1,c});
                grid[r+1][c]=grid[r][c]+1;
            }
            if(c-1>=0 && visited[r][c-1]==false && grid[r][c-1]==2147483647){
                q.push({r,c-1});
                grid[r][c-1]=grid[r][c]+1;
            }

        }
        
    }
};
