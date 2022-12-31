class Solution {
public:
    int res=0;
    void Dfs(vector<vector<int>>grid,int i,int j,int Row,int Col,int move,int ct) {
        // Checking valid move here
        if (i<0 || j<0 || i>=Row || j>=Col ||  grid[i][j]==-1) {
            return ;
        }
        // Reaching out the ending Square
        if (grid[i][j]==2 && ct==move+1) {
            res++;
            return;
        }
        // if (grid[i][j]==2) {
        //     return ;
        // }
        grid[i][j]=-1;  // Filling with -1 beacuse we alread visit it
        ct++;
        // Moving in Four directinal Way
        Dfs(grid,i-1,j,Row,Col,move,ct);
        Dfs(grid,i+1,j,Row,Col,move,ct);
        Dfs(grid,i,j-1,Row,Col,move,ct);
        Dfs(grid,i,j+1,Row,Col,move,ct);  
        grid[i][j]=0;  // Backtracking here
        return; 
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int Row=grid.size();
        int Col=grid[0].size();
        int move=0;
         // Checking that How manby cells have to be travelled
        for (int i=0;i<Row;i++) {
            for (int j=0;j<Col;j++) {
                if (grid[i][j]==0) {
                    move++;
                }
            }
        }
        // Starting the travesring over the Grid
        for (int i=0;i<Row;i++) {
            for (int j=0;j<Col;j++) {
                if (grid[i][j]==1) {
                    Dfs(grid,i,j,Row,Col,move,0);
                    return res;
                }
            }
        }
        return res;
    }
};
