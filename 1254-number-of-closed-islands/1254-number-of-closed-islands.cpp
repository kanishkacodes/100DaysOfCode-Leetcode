class Solution {
public:
    int closedIsland(vector<vector<int>>& g) {
        queue<pair<int,int>>q;
        int n=g.size(),m=g[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(g[i][j]==0){
                    g[i][j]=1;
                    q.push({i,j});}
                }
            }
        }
        while(q.size()){
            auto l=q.front();
            q.pop();
            int x=l.first;
            int y=l.second;
            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,1,-1};
            for(int i=0;i<4;i++){
                int nx=dx[i]+x;
                int ny=dy[i]+y;
                if(nx>=0 && nx<n && ny>=0 && ny<m && g[nx][ny]==0){
                    g[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        int ct=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!g[i][j]){
                    ct++;
                      q.push({i,j});
                       while(q.size()){
            auto l=q.front();
            q.pop();
            int x=l.first;
            int y=l.second;
            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,1,-1};
            for(int i=0;i<4;i++){
                int nx=dx[i]+x;
                int ny=dy[i]+y;
                if(nx>=0 && nx<n && ny>=0 && ny<m && g[nx][ny]==0){
                    g[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
                }
            }
        }
        return ct;
    }
};