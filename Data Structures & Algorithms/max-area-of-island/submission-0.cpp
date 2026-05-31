class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0)
                    continue;
                if(grid[i][j]==1){
                    int area = trav(grid,i,j);
                    maxarea = max(area,maxarea);
                }
            }
        }
        return maxarea;
    }
    int trav(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>=grid.size()||j<0 ||j>=grid[0].size())
            return 0;
        if(grid[i][j]==0)
            return 0;
        grid[i][j]=0;
        int area = 1;
        area += trav(grid,i-1,j);
        area +=trav(grid,i,j+1);
        area +=trav(grid,i+1,j);
        area +=trav(grid,i,j-1);

        return area;
    }
};
