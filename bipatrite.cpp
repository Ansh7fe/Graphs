#include<iostream>
#include<vector>
using namespace std;

bool dfs_helper(vector<int> adj,int i,int visited[],int parent,int color){
  visited[i]=color; //both mean visited
  for(auto it : adj[i]){
    if(visited==0){
      bool subprob=dfs_helper(adj,it,visited,i,3-color);
      if(subprob==false) return false;
    }
    else if(it!=parent and color==visited[it]){
      return false;
    }
  }


}
bool dfs(vector<int> adj,int n){

  int visited[n]={0};
  dfs_helper(adj,0,visited,1);


}

int main(){
  int n,m;
  cin>>n>>m;

  vector<int> adj[n];

  while(m--){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }


  
  return 0;
}