class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) 
    {
        int rows = box.size(), cols = box[0].size();
        
        vector<vector<char>> rotatedBox(cols, vector<char>(rows));
        
        for(int r = 0 ; r < rows ; ++r)
        {
            int right = cols - 1, left = right;
            while(right >= 0 && left >= 0)
            {
                while(right >= 0 && box[r][right] != '.')
                    --right;
                
                left = min(right - 1, left);
                while(left >= 0 && box[r][left] == '.')
                    --left;
                
                if(left >= 0 && box[r][left] == '*')
                    right = left - 1;
                else if(left >= 0 && box[r][left] == '#')
                    swap(box[r][left], box[r][right]);
            }
        }
        
        for(int r = 0 ; r < rows ; ++r)
            for(int c = 0 ; c < cols ; ++c)
                rotatedBox[c][rows - r - 1] = box[r][c];
        
        return rotatedBox;
    }
    
    
};