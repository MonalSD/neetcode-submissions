class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (recur(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
    bool recur(vector<vector<char>>& board,string& word,int r,int c,int i){
        if(i==word.size()){
            return true;
        }
        if(r<0||c<0 || r>=board.size()||c>=board[0].size()){
            return false;
        }
        if(board[r][c]!=word[i])
            return false;
        
        char temp = board[r][c];
        board[r][c] = '#';
        
        bool found =    recur(board,word,r+1,c,i+1)|| 
                        recur(board,word,r-1,c,i+1)||
                        recur(board,word,r,c+1,i+1)||
                        recur(board,word,r,c-1,i+1);

        board[r][c]=temp;

        return found;
    
    }
};
