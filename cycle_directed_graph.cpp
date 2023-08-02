#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int> *l;

public:
    Graph(int v) {
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y) {
        l[x].push_back(y);
    }

    void printEdges() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " -> ";
            for (int nbr : l[i]) {
                cout << nbr << ",";
            }
            cout << endl;
        }
    }

    bool cycle_helper(int node,bool *visited[],bool *stack[]){
      visited[node]=true;
      stack[node]=true;

      for(auto it:l[node]){
        if( stack[it]) return true;
        else if(!visited[it]){
          bool cycle=cycle_helper(it,visited,stack);
        }
      }

      stack[node]=false;
      return false;
    }
    bool cycle(){
      bool *visited= new bool[V];
      bool *stack=new bool[V];

    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.printEdges();
    return 0;
}
