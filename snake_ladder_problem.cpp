#include<iostream>
#include<map>
#include<queue>
#include<list>
using namespace std;
template<typename T>

class Graph{
  map<T,list<int> > adj;

public:
  void addEdge(int x,int y){
  adj[x].push_back(y);
  }

  int bfs(int src,int desti){
    queue<T> q;
    map<int,T> dist;

    for (auto node_pair : adj) {
      T  node = node_pair.first;
      dist[node] = INT_MAX;
    }

    q.push(src);
    dist[src] = 0;

    while(!q.empty()){
      T node=q.front();
      q.pop();

      for(auto it : adj[node]){
        if(dist[it]==INT_MAX){
          q.push(it);
          dist[it]=dist[node]+1;
        }
      }
    }
    return dist[desti];
  }


};

int main(){
  int board[36]={0};

  // sankes jump is negative and ladder jump is positive
  board[2]=13;
  board[5]=2;
  board[9]=18;
  board[18]=11;
  board[17]=-13;
  board[20]=-14;
  board[24]=-8;
  board[25]=10;
  board[32]=-2;
  board[34]=-22;

  // Add all edges to the graph
  Graph<int> g;
  for(int i=0;i<37;i++){
    for(int dice=1;dice<=6;dice++){
      int j=i+dice;
      j+=board[j];

      if(j<=36){
        g.addEdge(i,j);
      }
    }
  }
    g.addEdge(36,36);

   cout<<g.bfs(0,36);

  return 0;
}