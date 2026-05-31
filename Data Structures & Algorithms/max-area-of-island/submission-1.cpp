class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0)
                    continue;
                if(grid[i][j]==1){
                    int area =0;
                    trav(grid,i,j,area);
                    maxarea = max(area,maxarea);
                }
            }
        }
        return maxarea;
    }
    void trav(vector<vector<int>>& grid,int i,int j,int& area){
        if(i<0 || i>=grid.size()||j<0 ||j>=grid[0].size())
            return ;
        if(grid[i][j]==0)
            return ;
        grid[i][j]=0;
        area++;
        trav(grid,i-1,j,area);
        trav(grid,i,j+1,area);
        trav(grid,i+1,j,area);
        trav(grid,i,j-1,area);
    }
};
