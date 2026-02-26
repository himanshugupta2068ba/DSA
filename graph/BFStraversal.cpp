#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int>*l;
    public:
    Graph(int v){
        V=v;
        l=new list<int>[V];
    }

    void addEdge(int v,int u){
        l[v].push_back(u);
        l[u].push_back(v);
    }

    void bfs(int source){  //tc=O(V+E) sc=O(V)
        vector<bool> visited(V,false);
        queue<int> queue;

        visited[source]=true;
        queue.push  (source);

        while(!queue.empty()){
            int node=queue.front();
            cout<<node<<" ";
            queue.pop();

            for(auto neighbour:l[node]){
                if(!visited[neighbour]){
                    visited[neighbour]=true;
                    queue.push(neighbour);
                }
            }
        }
    }
};

int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,3);
    return 0;
}