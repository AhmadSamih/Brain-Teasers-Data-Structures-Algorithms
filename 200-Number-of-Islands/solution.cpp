class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int result = 0;
        if(grid.empty())return result;
        
       int i,j ; i = j = 0;
       int xdim  = grid.size();
       int ydim = grid[0].size();
       
       int ** visited = new int * [xdim];
       for(int ii = 0; ii< xdim; ii++){
           visited[ii] = new int [ydim];
           memset(visited[ii], 0 , ydim*sizeof(int));
        }
       
       for( i=0; i<xdim;i++){
           for( j = 0; j< ydim; j++){
                if(visited[i][j] || grid[i][j] == '0') continue;
                else
                {
                    result ++;
                    conn(i, j, xdim, ydim, grid, visited);
                }
           }
       }
        return result;
        
    }
    
    void conn(int i, int j, int xdim, int ydim, vector<vector<char>>& grid, int ** /*vector<vector<int>>&*/ visited){

        visited[i][j] = 1;
        //east
        if((j < ydim-1) && grid[i][j+1] == '1' && !visited[i][j+1]) conn(i, j + 1, xdim, ydim, grid, visited);
        //south
        if((i < xdim-1) && grid[i+1][j]== '1' && !visited[i+1][j]) conn(i+1, j, xdim, ydim, grid, visited);
        //west
        if((j > 0) && grid[i][j-1]== '1' && !visited[i][j-1]) conn(i, j-1, xdim, ydim, grid, visited);
        //north
        if((i > 0) && grid[i-1][j]== '1' && !visited[i-1][j]) conn(i-1, j, xdim, ydim, grid, visited);
    }
};