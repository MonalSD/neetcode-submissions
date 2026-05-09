class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int s = 0;
        int e = rows*cols -1;

        while(s<=e){
            int mid = s + (e-s)/2;
            int row = mid/cols;
            int col = mid%cols;
            if(target < matrix[row][col]){
                e = mid - 1;
            }
            else if(target > matrix[row][col]){
                s = mid + 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
