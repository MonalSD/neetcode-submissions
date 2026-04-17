class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char val = board[i][j];

                if(val == '.') continue;
                int boxIndex = (i/3)*3+(j/3);

                if(row[i].find(val)!=row[i].end()) return false;
                if(col[j].find(val)!=col[j].end()) return false;
                if(box[boxIndex].find(val)!=box[boxIndex].end()) return false;

                row[i].insert(val);
                col[j].insert(val);
                box[boxIndex].insert(val);

            }
        }

        return true;
    }
};
