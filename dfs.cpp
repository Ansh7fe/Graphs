#include<iostream>
#include<map>
#include<queue>
#include<list>

using namespace std;

template<typename T>
class Graph{
  map<T, list<T> > adj;

public:
  void addEdge(T x, T y){
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  void dfs_helper(T src,map<T,bool > &visited){
    // recursive function that will travel graph

    cout<<src<<" ";
    visited[src]=true;
    for(T it:adj[src]){
      if(!visited[it]){
        dfs_helper(it,visited)
      }
    }
  }

  void dfs(T src){
    map<T,bool > visited;

    for(auto p:adj){
      T node =p.first;
      visited[node]=false;
    }
    dfs_helper(src,visited);
  }
};

int main(){
  Graph<int> g;
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 5);

  g.dfs(0);
  return 0;
}
