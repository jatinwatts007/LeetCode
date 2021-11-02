class Solution {
public:
    int answer=0;
    void helper(vector<vector<int>>&g,int count,int ans,int i, int j){
        if(g[i][j]==2){
            if(count==ans) answer++;
            return;
        }
        g[i][j]=-1;
        if(i+1<g.size() && (g[i+1][j]==0 || g[i+1][j]==2)){
            helper(g,count+1,ans,i+1,j);
        }
        if(j+1<g[0].size() && (g[i][j+1]==0 || g[i][j+1]==2)){
            helper(g,count+1,ans,i,j+1);
        }
        if(i-1>=0 && (g[i-1][j]==0 || g[i-1][j]==2)){
            helper(g,count+1,ans,i-1,j);
        }
        if(j-1>=0 && (g[i][j-1]==0 || g[i][j-1]==2)){
            helper(g,count+1,ans,i,j-1);
        }
        g[i][j]=0;
        
    }
    int uniquePathsIII(vector<vector<int>>& g) {
        int count=0;
        pair<int,int>p;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==0 || g[i][j]==2) count++;
                if(g[i][j]==1){
                    p.first=i;
                    p.second=j;
                }
            }
        }
        helper(g,0,count,p.first,p.second);
        return answer;
    }
};
