#include<iostream>
#include<vector>
#include<list>
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

    void dfshelper(int source,vector<bool>& visited){  //tc=O(V+E) sc=O(V)
        visited[source]=true;
        cout<<source<<" ";

        for(auto neighbour:l[source]){
            if(!visited[neighbour]){
                dfshelper(neighbour,visited);
            }
        }
    }

    void dfs(){
        int source=0;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfshelper(i,visited);
            }
        }
        dfshelper(source,visited);
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