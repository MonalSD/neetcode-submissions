class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROW = board.size();
        int COL = board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<COL;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                board[0][i]='#';
            }    
        }
        for(int i=0;i<ROW;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                board[i][0]='#';
            } 
        }
        for(int i=0;i<COL;i++){
            if(board[ROW-1][i]=='O'){
                q.push({ROW-1,i});
                board[ROW-1][i]='#';
            }
        }
        for(int i=0;i<ROW;i++){
            if(board[i][COL-1]=='O'){
                q.push({i,COL-1});
                board[i][COL-1]='#';
            } 
        }

        while(!q.empty()){
            pair<int,int> curr = q.front();
            int r = curr.first;
            int c = curr.second;
            q.pop();
            if(r-1>=0 && board[r-1][c]=='O'){
                q.push({r-1,c});
                board[r-1][c]='#';
            }   
            if(c+1<COL && board[r][c+1]=='O'){
                q.push({r,c+1});
                board[r][c+1]='#';
            }
            if(r+1<ROW && board[r+1][c]=='O'){
                q.push({r+1,c});
                board[r+1][c]='#';
            }
            if(c-1>=0 && board[r][c-1]=='O'){
                q.push({r,c-1});
                board[r][c-1]='#';
            } 
        }

        //handle the zeroes
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }

    
};
