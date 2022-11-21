class Solution {
    private:
    int Helper(vector<vector<char>>&maze,vector<int>&e){
        queue<pair<int,int>>q;
        q.push({e[0],e[1]});
        // size maze in col & row
        int roW=maze.size();
        int Col=maze[0].size();
        int arX[4]={0,1,0,-1};
        int arY[4]={1,0,-1,0};
        int mov=1;
        maze[e[0]][e[1]]='+';
        while(!q.empty()){
            int l=q.size();
            for(int k=0;k<l;k++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int l=0;l<4;l++){
                    int x=i+arX[l];
                    int y=j+arY[l];
                    if(x<0||y<0||x>=roW||y>=Col||maze[x][y]=='+') continue;
                    if(x==0||y==0||x==roW-1||y==Col-1) return mov;
                    maze[x][y]='+';
                    q.push({x,y});
                }
            }
           mov++;
        }
        return -1;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        return Helper(maze,entrance);
    }
};
