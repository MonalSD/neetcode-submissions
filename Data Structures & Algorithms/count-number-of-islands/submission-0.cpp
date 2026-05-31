class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> copy(grid.size(),vector<bool>(grid[0].size(),false));
        int count =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='0')
                    continue; 
                if(grid[i][j]=='1' && copy[i][j]==false){
                    trav(grid,i,j,copy);
                    count++;
                }
            }
        }
        return count;
    }
    void trav(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>& copy){
        if((i<0 || i>=grid.size()) || (j<0 || j>=grid[0].size())){
            return ;
        }
        if(copy[i][j]==true){
            return ;
        }
        if(grid[i][j]=='0')
            return;
            
        copy[i][j]=true;
        trav(grid,i-1,j,copy);
        trav(grid,i,j+1,copy);
        trav(grid,i+1,j,copy);
        trav(grid,i,j-1,copy);
    }
};
