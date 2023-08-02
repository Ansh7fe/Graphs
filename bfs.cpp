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

  void bfs(T src){
    map<T, bool> visited;
    queue<T> q;

    q.push(src);
    visited[src] = true;

    while(!q.empty()){
      T node = q.front();
      q.pop();
      cout<<node<<"-";
      for(auto it : adj[node]){
        if(visited[it] == false){
          q.push(it);
          visited[it] = true;
        }
      }
    }
  }
};

int main(){
  Graph<int> g;
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 5);

  g.bfs(0);

  return 0;
}
