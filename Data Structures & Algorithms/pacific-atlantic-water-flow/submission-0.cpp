class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int ROW = heights.size();
        int COL = heights[0].size();
        vector<vector<bool>> paci(ROW, vector<bool>(COL, false));
        vector<vector<bool>> atla(ROW, vector<bool>(COL, false));
        queue<pair<int,int>> atlq;
        queue<pair<int,int>> paciq;
        for(int j=0;j<COL;j++){
            paci[0][j]=true;
            paciq.push({0,j});
        }
        for(int j=0;j<ROW;j++){
            paci[j][0]=true;
            paciq.push({j,0});
        }
        
        for(int j=0;j<COL;j++){
            atla[ROW-1][j]=true;
            atlq.push({ROW-1,j});
        }
        for(int j=0;j<ROW;j++){
            atla[j][COL-1]=true;
            atlq.push({j,COL-1});
        }

        bfs(heights,paci,paciq);
        bfs(heights,atla,atlq);

        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(paci[i][j]==true && atla[i][j]==true)
                {
                    res.push_back({i,j});
                }

            }
        }
        return res;
    }

    void bfs(vector<vector<int>>& heights,vector<vector<bool>>& ocean, queue<pair<int,int>>& q){
        int ROW = heights.size();
        int COL = heights[0].size();
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            if(r-1>=0 && (heights[r][c]<=heights[r-1][c] && ocean[r-1][c]!=true)){
                q.push({r-1,c});
                ocean[r-1][c]=true;
            }
            if(c+1<COL && (heights[r][c]<=heights[r][c+1] && ocean[r][c+1]!=true)){
                q.push({r,c+1});
                ocean[r][c+1]=true;
            }
            if(r+1<ROW && (heights[r][c]<=heights[r+1][c] && ocean[r+1][c]!=true)){
                q.push({r+1,c});
                ocean[r+1][c]=true;
            }
            if(c-1>=0 && (heights[r][c]<=heights[r][c-1] && ocean[r][c-1]!=true)){
                q.push({r,c-1});
                ocean[r][c-1]=true;
            }
        }
    }
};
