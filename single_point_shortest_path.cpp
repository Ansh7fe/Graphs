#include <iostream>
#include <map>
#include <queue>
#include <list>
#include <climits>

using namespace std;

template<typename T>
class Graph {
  map<T, list<T> > adj;

public:
  void addEdge(T x, T y) {
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  void bfs(T src) {
    map<T, int> dist;
    queue<T> q;
    
    for (auto node_pair : adj) {
      T node = node_pair.first;
      dist[node] = INT_MAX;
    }
    
    q.push(src);
    dist[src] = 0;

    while (!q.empty()) {
      T node = q.front();
      q.pop();
      // cout<<node<<"-";
      for (auto it : adj[node]) {
        if (dist[it] == INT_MAX) {
          q.push(it);
          dist[it] = dist[node] + 1;
        }
      }
    }

    for (auto node_pair : adj) {
      T node = node_pair.first;
      int d = dist[node] + 1;
      cout << "Node " << node << " Distance from src: " << d << endl;
    }
  }
};

int main() {
  Graph<int> g;
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 5);

  g.bfs(0);

  return 0;
}
